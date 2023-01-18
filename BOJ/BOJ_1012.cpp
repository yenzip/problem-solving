#include <bits/stdc++.h>

using namespace std;

int M, N;	// M : 가로(열), N : 세로(행)
int field[50][50];	// field: 배추밭
int isVisited[50][50];	// isVisited: 방문 여부
int dRow[4] = { 0, 0, -1, 1 };
int dCol[4] = { 1, -1, 0, 0 };	// dRow, dCol: 상하좌우 변이

void dfs(int row, int col) {
	isVisited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dRow[i];
		int nextCol = col + dCol[i];

		if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) {	// nextRow, nextCol - 범위 벗어남
			continue;
		}
		else if (field[nextRow][nextCol] == 1 && !isVisited[nextRow][nextCol]) {
			dfs(nextRow, nextCol);
		}
	}
}

int main() {
	int T;

	cin >> T;

	while (T--) {
		int K;	// K: 배추 개수

		cin >> M >> N >> K;

		memset(field, 0, sizeof(field));	
		memset(isVisited, false, sizeof(isVisited));

		while (K--) {	// 배추 심기
			int X, Y;	// X, Y: 배추 좌표
			cin >> X >> Y;
			field[Y][X] = 1;
		}

		int warm = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1 && !isVisited[i][j]) {
					dfs(i, j);
					warm++;
				}
			}
		}

		cout << warm << '\n';
	}

	return 0;
}