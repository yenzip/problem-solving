#include <bits/stdc++.h>
using namespace std;

int N;
int board[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int land = 0;
int answer = 10000;

struct info {
	int x;
	int y;
	int bridge_length;
};

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void dfs(int x, int y) {	// 섬 구분하기
	visited[x][y] = true;
	board[x][y] = land;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && board[nx][ny] == 1 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int bfs(int land_num) {	// 섬 별 다리 건설
	queue<info> q;	// {x, y, bridge_length}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == land_num) {
				visited[i][j] = true;
				q.push({ i, j, 0 });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int b = q.front().bridge_length;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOut(nx, ny)) {	
				continue;
			}
			if (board[nx][ny] && board[nx][ny] != land_num) {	// 다른 섬에 도달하면 다리 길이 반환
				return b;
			}
			if (!board[nx][ny] && !visited[nx][ny]) {	// 0인 부분 다리 건설
				visited[nx][ny] = true;
				q.push({ nx, ny, b + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {	// 섬 구분하기
		for (int j = 0; j < N; j++) {
			if (board[i][j] && !visited[i][j]) {
				land++;
				dfs(i, j);
			}
		}
	}

	for (int i = 1; i <= land; i++) {
		memset(visited, false, sizeof(visited));
		answer = min(answer, bfs(i));
	}

	cout << answer << '\n';

	return 0;
}