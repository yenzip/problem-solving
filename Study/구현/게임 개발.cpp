#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y, direction;
int A[50][50];
bool visited[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void turnLeft() {
	direction -= 1;
	if (direction == -1) {
		direction = 3;
	}
}

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	cin >> x >> y >> direction;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;		// 방문한 칸의 수
	int turnCnt = 0;	// 회전 횟수

	while (true) {
		turnLeft();	// 1. 왼쪽 방향으로 회전
		
		int nx = x + dx[direction];	
		int ny = y + dy[direction];

		if (!isOut(nx, ny) && A[nx][ny] == 0 && !visited[nx][ny]) {	// 2-1. 방문하지 않은 칸 존재
			visited[nx][ny] = true;
			answer++;
			x = nx;
			y = ny;
			turnCnt = 0;
			continue;
		}
		else {	// 2-2. 회전만 수행하고 1단계로 돌아감
			turnCnt++;
		}

		if (turnCnt == 4) {	// 3. 4 방향 모두 가본 칸이거나 바다인 경우
			nx = x - dx[direction];	// 방향 유지한 채 1단계로 돌아감
			ny = y - dy[direction];

			if (!isOut(nx, ny) && A[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			else {	// 바다 칸인 경우 움직임 종료
				break;
			}
			
			turnCnt = 0;
		}
	}

	cout << answer;

	return 0;
}
