#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> answer;

bool isOut(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}

void bfs(vector<string> maps, int sx, int sy) {
	int dist = 0;
	queue<pair<int, int>> q;
	visited[sx][sy] = true;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		dist += maps[x][y] - '0';
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && maps[nx][ny] != 'X' && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	answer.push_back(dist);
}

vector<int> solution(vector<string> maps) {

	n = maps.size();
	m = maps[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] != 'X' && !visited[i][j]) {
				bfs(maps, i, j);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer.size() ? answer : {-1};
}