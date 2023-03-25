#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y;
int board[200][200];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
priority_queue<pair<int, pair<int, int>>> tmp;

int isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void bfs() {
	priority_queue<pair<int, pair<int, int>>> pq(tmp);
	tmp = priority_queue<pair<int, pair<int, int>>>();

	while (!pq.empty()) {
		int type = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && board[nx][ny] == 0) {
				board[nx][ny] = type;
				tmp.push({ -type, {nx, ny} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				tmp.push({ -board[i][j], {i, j} });
			}
		}
	}
	cin >> S >> X >> Y;

	while (S--) {
		bfs();
	}

	cout << board[X - 1][Y - 1] << '\n';

	return 0;
}