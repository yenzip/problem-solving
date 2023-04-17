#include <bits/stdc++.h>
using namespace std;

int T;
char board[100][100];

int check_length(int x, int y, int len) {
	for (int i = y, j = y + len - 1; i <= j; i++, j--) {
		if (board[x][i] != board[x][j]) {
			return 1;
		}
	}
	return len;
}

int check_height(int x, int y, int len) {
	for (int i = x, j = x + len - 1; i <= j; i++, j--) {
		if (board[i][y] != board[j][y]) {
			return 1;
		}
	}
	return len;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		cin >> T;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> board[i][j];
			}
		}

		int answer = 1;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				for (int k = 2; k < 100; k++) {
					if (j + k <= 100) {
						answer = max(answer, check_length(i, j, k));
					}
					if (i + k <= 100) {
						answer = max(answer, check_height(i, j, k));
					}
				}
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}