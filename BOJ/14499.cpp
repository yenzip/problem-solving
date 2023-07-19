#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K;
int A[20][20];
int direction;
int dx[5] = { 0, 0, 0, -1, 1 };	// 동 - 서 - 북 - 남
int dy[5] = { 0, 1, -1, 0, 0 };
int dice[6];	// 윗면(0) - 바닥면(1) - 북(2) - 남(3) - 동(4) - 서(3)

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void rotation() {
	int tmp = dice[0];	// 주사위 윗면

	if (direction == 1) {	// 서쪽으로 회전
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (direction == 2) {	// 동쪽으로 회전
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
	else if (direction == 3) {	// 북쪽으로 회전
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	else if (direction == 4) {	// 남쪽으로 회전
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> direction;

		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (isOut(nx, ny)) {
			continue;
		}

		rotation();	// 주사위 회전

		if (A[nx][ny] == 0) {	// 이동한 칸 0이라면, 주사위 바닥면에 쓰여 있는 수 복사
			A[nx][ny] = dice[1];	
		}
		else {					// 이동한 칸 0이 아니라면, 주사위 바닥면으로 복사
			dice[1] = A[nx][ny];
			A[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << dice[0] << "\n";
	}

	return 0;
}