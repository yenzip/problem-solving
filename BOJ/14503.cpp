#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y, d;
int A[50][50];
bool visited[50][50];
int dx[4] = { -1, 0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };
int answer;

void simulation(int x, int y, int direction) {
	if (!visited[x][y] && A[x][y] == 0) {	// 1. 현재 칸 청소
		visited[x][y] = true;
		answer++;
	}

	int curDirection = direction;

	for (int i = 0; i < 4; i++) {
		int nextDirection = (curDirection + 3) % 4;
		int nx = x + dx[nextDirection];
		int ny = y + dy[nextDirection];

		if (!visited[nx][ny] && A[nx][ny] == 0) {	// 3. 주변 4칸 중 청소되지 않은 빈 칸 존재
			simulation(nx, ny, nextDirection);
			return;
		}

		curDirection = nextDirection;
	}

	int nx = x - dx[curDirection];	// 2. 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
	int ny = y - dy[curDirection];	// 바라보는 방향을 유지한 채로 후진

	if (A[nx][ny] == 1) {	//	후진할 수 없다면 작동 종료
		return;
	}
	else {
		simulation(nx, ny, curDirection);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	simulation(x, y, d);

	cout << answer;

	return 0;
}