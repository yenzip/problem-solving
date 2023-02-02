#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
int board[25][25];
bool visited[25][25] = { false, };
int dRow[4] = { 1, -1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };
int cnt;	// 단지 수

int isOut(int row, int col) {
	return (row < 0 || row >= N || col < 0 || col >= N);
}

void dfs(int row, int col) {
	visited[row][col] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dRow[i];
		int nextCol = col + dCol[i];

		if (!isOut(nextRow, nextCol) && board[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
			dfs(nextRow, nextCol);
		}
	}
}

int main() {
	int total = 0;	// 총 단지수
	vector<int> v;	// 각 단지내 집의 수

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (board[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				total++;
				v.push_back(cnt);
			}
		}
	}

	printf("%d\n", total);

	sort(v.begin(), v.end());
	for (int i : v) {
		printf("%d\n", i);
	}

	return 0;
}