#include <bits/stdc++.h>

using namespace std;

int I;
int level[300][300];
int dRow[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dCol[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
pair<int, int> s, e;	// start, end

int isOut(int row, int col) {
	return (row < 0 || row >= I || col < 0 || col >= I);
}

void bfs() {
	queue<pair<int, int>> q;

	level[s.first][s.second] = 0;
	q.push({ s.first, s.second });

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
 		q.pop();

		if (row == e.first && col == e.second) {
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nextRow = row + dRow[i];
			int nextCol = col + dCol[i];

			if (!isOut(nextRow, nextCol) && level[nextRow][nextCol] == -1) {
				level[nextRow][nextCol] = level[row][col] + 1;
				q.push({ nextRow, nextCol });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> I;

		cin >> s.first >> s.second;
		cin >> e.first >> e.second;

		memset(level, -1, sizeof(level));

		bfs();

		cout << level[e.first][e.second] << '\n';
	}

	return 0;
}