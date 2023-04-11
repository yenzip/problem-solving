#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Info {
	int x, y, bridge;
};

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(int sx, int sy) {
	deque<Info> dq;
	visited[sx][sy] = true;
	dq.push_back({ sx, sy, 0 });

	while (!dq.empty()) {
		int x = dq.front().x;
		int y = dq.front().y;
		int b = dq.front().bridge;
		dq.pop_front();

		if (x == N - 1 && y == M - 1) {
			cout << b << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOut(nx, ny) || visited[nx][ny]) {
				continue;
			}

			visited[nx][ny] = true;
			if (board[nx][ny]) {
				dq.push_back({ nx, ny, b + 1 });
			}
			else {
				dq.push_front({ nx, ny, b });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	bfs(0, 0);	// 0-1 BFS

	return 0;
}