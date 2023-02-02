#include <bits/stdc++.h>

using namespace std;

int N;
int board[25][25];
bool visited[25][25] = { false, };
int dRow[4] = { 1, -1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };
int cnt = 0;

int isOut(int row, int col) {
	return (row < 0 || row >= N || col < 0 || col >= N);
}

void bfs(int startRow, int startCol) {
	queue<pair<int, int>> q;

	visited[startRow][startCol] = true;
	cnt++;
	q.push({ startRow, startCol });

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dRow[i];
			int nextCol = col + dCol[i];

			if (!isOut(nextRow, nextCol) && board[nextRow][nextCol] && !visited[nextRow][nextCol]) {
				visited[nextRow][nextCol] = true;
				cnt++;
				q.push({ nextRow, nextCol });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int total = 0;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (board[i][j] && !visited[i][j]) {
				bfs(i, j);
				v.push_back(cnt);
				total++;
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