#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int board[101][101];
map<int, char> m;	// { 초, 방향 }
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };
int direction;

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > N);
}

void turnDirection(char c) {
	if (c == 'L') {	// 왼쪽으로 90도 회전
		direction -= 1;
		if (direction == -1) {
			direction = 3;
		}
	}
	else {	// 오른쪽으로 90도 회전
		direction += 1;
		if (direction == 4) {
			direction = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;	// 사과의 위치 1로 표시
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int a;
		char b;
		cin >> a >> b;
		m[a] = b;	// 뱀의 방향 변환 정보
	}

	int answer = 0;
	int x = 1;
	int y = 1;

	queue<pair<int, int>> body;	// 뱀의 몸 좌표
	body.push({ x, y });

	direction = 1;	// 뱀은 처음에 오른쪽(동)을 향한다

	while (true) {
		answer++;

		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (isOut(nx, ny) || visited[nx][ny]) {	// 벽 또는 몸과 부딫히면 게임 오버
			break;
		}

		visited[nx][ny] = true;
		body.push({ nx, ny });

		if (board[nx][ny] == 1) {	// 이동한 칸에 사과가 있다면
			board[nx][ny] = 0;	// 사과 없어짐
		}
		else {	// 이동한 칸에 사과가 없다면
			visited[body.front().first][body.front().second] = false;	// 꼬리가 위치한 칸 비워준다
			body.pop();
		}

		x = nx;
		y = ny;

		if (m.count(answer) != 0) {	// 방향 전환
			turnDirection(m[answer]);
		}
	}

	cout << answer;

	return 0;
}