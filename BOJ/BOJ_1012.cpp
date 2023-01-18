#include <bits/stdc++.h>

using namespace std;

int M, N;	// M : ����(��), N : ����(��)
int field[50][50];	// field: ���߹�
int isVisited[50][50];	// isVisited: �湮 ����
int dRow[4] = { 0, 0, -1, 1 };
int dCol[4] = { 1, -1, 0, 0 };	// dRow, dCol: �����¿� ����

void dfs(int row, int col) {
	isVisited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dRow[i];
		int nextCol = col + dCol[i];

		if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) {	// nextRow, nextCol - ���� ���
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
		int K;	// K: ���� ����

		cin >> M >> N >> K;

		memset(field, 0, sizeof(field));	
		memset(isVisited, false, sizeof(isVisited));

		while (K--) {	// ���� �ɱ�
			int X, Y;	// X, Y: ���� ��ǥ
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