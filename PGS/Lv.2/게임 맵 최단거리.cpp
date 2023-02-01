#include <bits/stdc++.h>
using namespace std;

int n, m;	// 세로(행), 가로(열)
int level[100][100];	// visited
int dRow[4] = { 0, 0, -1, 1 };	// 상하좌우
int dCol[4] = { 1, -1, 0, 0 };

int isOut(int row, int col) {
	return (row < 0 || row >= n || col < 0 || col >= m);
}

int solution(vector<vector<int> > maps) {
	int answer;

	n = maps.size();
	m = maps[0].size();	

	memset(level, -1, sizeof(level));

	queue<pair<int, int>> q;	// { row, col }

	level[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dRow[i];
			int nextCol = col + dCol[i];

			if (!isOut(nextRow, nextCol) && maps[nextRow][nextCol] == 1 && level[nextRow][nextCol] == -1) {
				level[nextRow][nextCol] = level[row][col] + 1;
				q.push({ nextRow, nextCol });
			}
		}
	}

	answer = level[n - 1][m - 1];

	return answer;
}