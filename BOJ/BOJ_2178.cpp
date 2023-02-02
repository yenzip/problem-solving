#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[100][100];
int level[100][100];
int dRow[4] = { 1, -1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };

int isOut(int row, int col) {
	return (row < 0 || row >= N || col < 0 || col >= M);
}

void bfs() {
	queue<pair<int, int>> q;

	level[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dRow[i];
			int nextCol = col + dCol[i];

			if (!isOut(nextRow, nextCol) && board[nextRow][nextCol] && level[nextRow][nextCol] == -1) {
				level[nextRow][nextCol] = level[row][col] + 1;
				q.push({ nextRow, nextCol });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	memset(level, -1, sizeof(level));

	bfs();

	cout << level[N - 1][M - 1];

	return 0;
}
