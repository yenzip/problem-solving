#include<vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int level[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(vector<vector<int>> &maps) {
	queue<pair<int, int>> q;

	level[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOut(nx, ny) || maps[nx][ny] == 0) {
				continue;
			}
			else if (level[nx][ny] == -1) {
				level[nx][ny] = level[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int solution(vector<vector<int> > maps)
{

	N = maps.size();
	M = maps[0].size();

	memset(level, -1, sizeof(level));

	bfs(maps);

	return level[N - 1][M - 1];
}