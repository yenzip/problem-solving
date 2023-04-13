#include <bits/stdc++.h>
using namespace std;

int N;
char board[8][8];

bool check_length(int x, int y) {
	for (int i = y, j = y + N - 1; i <= (2 * y + N -1) / 2; i++, j--) {
		if (board[x][i] != board[x][j]) {
			return false;
		}
	}
	return true;
}

bool check_height(int x, int y) {
	for (int i = x, j = x + N - 1; i <= (2 * x + N - 1) / 2; i++, j--) {
		if (board[i][y] != board[j][y]) {
			return false;
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 1; t++) {
		cin >> N;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> board[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				answer += check_length(i, j);
				answer += check_height(j, i);
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}