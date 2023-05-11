#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	visited[sx][sy] = true;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && board[nx][ny] && !visited[nx][ny]) {
				board[nx][ny] = board[x][y] + 1;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	bfs(0, 0);

	cout << board[N - 1][M - 1];

	return 0;
}