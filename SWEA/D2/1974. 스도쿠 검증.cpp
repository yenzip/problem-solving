#include <bits/stdc++.h>
using namespace std;

int T;
int board[9][9];
bool A[10];

bool check_length(int idx) {
	int cnt = 0;
	memset(A, false, sizeof(A));
	for (int i = 0; i < 9; i++) {
		int n = board[idx][i];
		if (!A[n]) {
			A[n] = true;
			cnt++;
		}
	}
	return cnt == 9 ? true : false;
}

bool check_height(int idx) {
	int cnt = 0;
	memset(A, false, sizeof(A));
	for (int i = 0; i < 9; i++) {
		int n = board[i][idx];
		if (!A[n]) {
			A[n] = true;
			cnt++;
		}
	}
	return cnt == 9 ? true : false;
}

bool check_square(int idx) {
	int cnt = 0;
	memset(A, false, sizeof(A));
	map<int, pair<int, int>> m = { {0, {0, 0}}, {1, {0, 3}}, {2, {0, 6}},
								   {3, {3, 0}}, {4, {3, 3}}, {5, {3, 6}},
								   {6, {6, 0}}, {7, {6, 3}}, {8, {6, 6}},
	};
	int row = m[idx].first, col = m[idx].second;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			int n = board[i][j];
			if (!A[n]) {
				A[n] = true;
				cnt++;
			}
		}
	}
	return cnt == 9 ? true : false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}
		bool answer = true;
		for (int i = 0; i < 9; i++) {
			if (!check_length(i)) {
				answer = false;
				break;
			}
			if (!check_height(i)) {
				answer = false;
				break;
			}
			if (!check_square(i)) {
				answer = false;
				break;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}