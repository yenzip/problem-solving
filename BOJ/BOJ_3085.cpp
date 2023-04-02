#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> board;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	board.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int maxRow = 0, maxCol = 0;
	vector<vector<char>> tmp;
	for (int i = 0; i < N; i++) {	// 1. 인접한 행끼리 교환
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] != board[i][j + 1]) {
				tmp = board;
				swap(tmp[i][j], tmp[i][j + 1]);	// 교환

				// 연속 행 검사
				for (int k = 0; k < N; k++) {
					int count = 0;
					for (int l = 0; l < N; l++) {
						if (l < N -1 && tmp[k][l] == tmp[k][l + 1]) {
							count += 2;
							if (l - 1 >= 0 && tmp[k][l - 1] == tmp[k][l]) {
								count--;
							}
						}
						else {
							if (count) {
								maxRow = max(maxRow, count);
							}
							count = 0;
						}
					}
				}

				// 연속 열 검사
				for (int l = 0; l < N; l++) {
					int count = 0;
					for (int k = 0; k < N; k++) {
						if (k < N -1 && tmp[k][l] == tmp[k + 1][l]) {
							count += 2;
							if (k - 1 >= 0 && tmp[k - 1][l] == tmp[k][l]) {
								count--;
							}
						}
						else {
							if (count) {
								maxCol = max(maxCol, count);
							}
							count = 0;
						}
					}
				}
			}
		}
	}

	for (int j = 0; j < N; j++) {	// 2. 인접한 열끼리 교환
		for (int i = 0; i < N - 1; i++) {
			if (board[i][j] != board[i + 1][j]) {
				tmp = board;
				swap(tmp[i][j], tmp[i + 1][j]);	// 교환

				// 연속 행 검사
				for (int k = 0; k < N; k++) {
					int count = 0;
					for (int l = 0; l < N; l++) {
						if (l < N - 1 && tmp[k][l] == tmp[k][l + 1]) {
							count += 2;
							if (l - 1 >= 0 && tmp[k][l - 1] == tmp[k][l]) {
								count--;
							}
						}
						else {
							if (count) {
								maxRow = max(maxRow, count);
							}
							count = 0;
						}
					}
				}

				// 연속 열 검사
				for (int l = 0; l < N; l++) {
					int count = 0;
					for (int k = 0; k < N; k++) {
						if (k < N - 1 && tmp[k][l] == tmp[k + 1][l]) {
							count += 2;
							if (k - 1 >= 0 && tmp[k - 1][l] == tmp[k][l]) {
								count--;
							}
						}
						else {
							if (count) {
								maxCol = max(maxCol, count);
							}
							count = 0;
						}
					}
				}
			}
		}
	}

	int maxCandy = max(maxRow, maxCol);
	cout << maxCandy << '\n';

	return 0;
}