#include <bits/stdc++.h>
using namespace std;

#define INF 10
int T, N;
int board[125][125];
int level[125][125];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void dijkstra(int x, int y) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -board[x][y], {x, y} });
	level[x][y] = board[x][y];

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now_x = pq.top().second.first;
		int now_y = pq.top().second.second;
		pq.pop();
		
		if (level[now_x][now_y] < dist) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			int cost = dist + board[next_x][next_y];

			if (isOut(next_x, next_y)) {
				continue;
			}
			else if (cost < level[next_x][next_y]) {
				level[next_x][next_y] = cost;
				pq.push({ -cost, {next_x, next_y} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		memset(level, INF, sizeof(level));
		dijkstra(0, 0);
		cout << level[N - 1][N - 1] << '\n';
	}

	return 0;
}
