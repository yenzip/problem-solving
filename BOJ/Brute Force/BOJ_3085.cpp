#include <bits/stdc++.h>
using namespace std;

int N;
char board[50][50];

int check() {
	int maxVal = 0;

	for (int i = 0; i < N; i++) {	
		int count = 1;	// 연속 행 검사
		for (int j = 1; j < N; j++) {
			if (board[i][j - 1] == board[i][j]) {
				count++;
			}
			else {
				count = 1;
			}
			maxVal = max(maxVal, count);
		}

		count = 1;	// 연속 열 검사
		for (int j = 1; j < N; j++) {
			if (board[j - 1][i] == board[j][i]) {
				count++;
			}
			else {
				count = 1;
			}
			maxVal = max(maxVal, count);
		}
	}

	return maxVal;
}

int  main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (board[i][j - 1] != board[i][j]) {	// 색이 다른 인접한 두 칸 [행] 교환
				swap(board[i][j - 1], board[i][j]);
				answer = max(answer, check());
				swap(board[i][j - 1], board[i][j]);	
			}
			if (board[j - 1][i] != board[j][i]) {	// 색이 다른 인접한 두 칸 [열] 교환
				swap(board[j - 1][i], board[j][i]);
				answer = max(answer, check());
				swap(board[j - 1][i], board[j][i]);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}