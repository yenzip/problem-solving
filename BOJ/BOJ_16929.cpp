#include <bits/stdc++.h>

using namespace std;

int N, M;
char board[50][50];
bool visited[50][50];
int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };
int sX, sY;
char color;
bool isCycle = false;

int isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void dfs(int x, int y, int depth) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nX = x + dX[i];
		int nY = y + dY[i];

		if (isOut(x, y) || board[nX][nY] != color) {
			continue;
		}

		if (!visited[nX][nY]) {
			dfs(nX, nY, depth + 1);
		}
		else if (nX == sX && nY == sY && depth >= 3) {
			isCycle = true;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, false, sizeof(visited));
			sX = i;	// start
			sY = j;	// start
			color = board[i][j];

			dfs(i, j, 0);

			if (isCycle) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}