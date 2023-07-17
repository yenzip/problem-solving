#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y, d;
int A[50][50];
bool visited[50][50];
int dx[4] = { -1, 0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;
	int turnCnt = 0;
	int direction = d;

	while (true) {
		if (!visited[x][y] && A[x][y] == 0) {
			visited[x][y] = true;
			answer++;
		}

		int curDirection = direction;

		for (int i = 0; i < 4; i++) {
			int nextDirection = (curDirection + 3) % 4;
			int nx = x + dx[nextDirection];
			int ny = y + dy[nextDirection];

			if (!visited[nx][ny] && A[nx][ny] == 0) {
				x = nx;
				y = ny;
				direction = nextDirection;
				turnCnt = 0;
				break;
			}
			else {
				turnCnt++;
			}

			curDirection = nextDirection;
		}

		if (turnCnt == 4) {
			int nx = x - dx[direction];
			int ny = y - dy[direction];

			if (A[nx][ny] == 1) {
				break;
			}
			else {
				x = nx;
				y = ny;
				turnCnt = 0;
			}
		}
	}

	cout << answer;

	return 0;
}