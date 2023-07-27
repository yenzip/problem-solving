#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[21][21];
int dice[6] = { 1, 6, 2, 5, 3, 4 };	// 위(0), 아래(1), 북(2), 남(3), 동(4), 서(5)
bool visited[21][21];
int dx[4] = { -1, 0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > M);
}

int bfs(int x, int y, int B) {
	queue<pair<int, int>> q;
	int dist = 0;

	memset(visited, false, sizeof(visited));

	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		dist++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && !visited[nx][ny] && A[nx][ny] == B) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return dist;
}

void rollDice(int direction) {
	int tmp = dice[0];
	if (direction == 0) {	// 북으로 회전
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	if (direction == 1) {	// 동으로 회전
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
	if (direction == 2) {	// 남으로 회전
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	if (direction == 3) {	// 서로 회전
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;	// 점수의 합 구하기
	int x = 1, y = 1;
	int direction = 1;	// 처음 주사위 이동 방향은 동쪽

	while (K--) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (isOut(nx, ny)) {	// 1. 이동 방향에 칸이 없다면 이동 방향을 반대로
			direction = (direction + 2) % 4;
			nx = x + dx[direction];
			ny = y + dy[direction];
		}

		rollDice(direction);	// 1. 주사위 굴리기

		int B = A[nx][ny];
		int C = bfs(nx, ny, B);	// 2. 점수 획득
		answer += B * C;

		if (dice[1] > B) {		// 3. 주사위 아랫면(A)와 B 비교해 이동방향 결정
			direction = (direction + 1) % 4;	// 시계 방향 회전
		}
		else if (dice[1] < B) {
			direction = (direction + 3) % 4;	// 반시계 방향 회전
		}

		x = nx;
		y = ny;
	}

	cout << answer;

	return 0;
}