#include <bits/stdc++.h>
using namespace std;

int T, N, M, K, x, y;
int A[50][50];
bool visited[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && A[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> M >> K;

		memset(A, 0, sizeof(A));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			A[x][y] = 1;
		}

		int answer = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] && !visited[i][j]) {
					dfs(i, j);
					answer++;
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}
