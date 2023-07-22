#include <bits/stdc++.h>
using namespace std;

int T, I;
int sx, sy;
int ex, ey;
int level[300][300];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= I || y < 0 || y >= I);
}

void bfs(int sx, int sy, int ex, int ey) {
	queue<pair<int, int>> q;

	level[sx][sy] = 0;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == ex && y == ey) {
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && level[nx][ny] == -1) {
				level[nx][ny] = level[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> I;
		cin >> sx >> sy >> ex >> ey;

		memset(level, -1, sizeof(level));

		bfs(sx, sy, ex, ey);
		cout << level[ex][ey] << "\n";
	}

	return 0;
}