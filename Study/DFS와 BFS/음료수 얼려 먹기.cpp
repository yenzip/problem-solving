#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1000][1000];
int visited[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && !board[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	int count = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j] && !visited[i][j]) {
				dfs(i, j);
				count++;
			}
		}
	}

	cout << count << '\n';

	return 0;
}