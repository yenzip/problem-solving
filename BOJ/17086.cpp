#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[50][50];
int dist[50][50];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
queue<pair<int, int>> q;
int answer;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOut(nx, ny) || A[nx][ny]) {
				continue;
			}

			if (dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				answer = max(answer, dist[nx][ny]);
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
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];

			if (A[i][j]) {
				q.push({ i, j });
			}
		}
	}

	bfs();

	cout << answer;

	return 0;
}