#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[8][8];
int tmp[8][8];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && tmp[nx][ny] == 0) {
			tmp[nx][ny] = 2;
			virus(nx, ny);
		}
	}
}

void wall(int count) {
	if (count == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 2) {
					virus(i, j);
				}
			}
		}

		int safe_zone = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 0) {
					safe_zone++;
				}
			}
		}
		result = max(result, safe_zone);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				count++;
				wall(count);
				board[i][j] = 0;
				count--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	wall(0);

	cout << result << '\n';

	return 0;
}