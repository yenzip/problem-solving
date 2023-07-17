#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int A[101][101];
map<int, char> m;	// { 초, 방향 }
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> body;	// 뱀의 몸 좌표

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > N);
}

int turnDirection(char C, int direction) {
	if (C == 'L') {	// 왼쪽 90도 회전
		return (direction + 3) % 4;
	}
	else {			// 오른쪽 90도 회전
		return (direction + 1) % 4;
	}
}

void simulation(int x, int y, int direction, int answer) {

	int nx = x + dx[direction];
	int ny = y + dy[direction];

	if (isOut(nx, ny) || visited[nx][ny]) {	// 벽이나 자신의 몸과 부딫히면 게임 종료
		cout << answer;
		return;
	}

	visited[nx][ny] = true;
	body.push({ nx, ny });

	if (A[nx][ny] == 1) {	// 이동한 칸에 사과가 있다면
		A[nx][ny] = 0;
	}
	else {	// 이동한 칸에 사과가 없다면, 꼬리칸 비우기
		visited[body.front().first][body.front().second] = false;
		body.pop();
	}

	if (m.count(answer) != 0) {	// 방향 변환
		direction = turnDirection(m[answer], direction);
	}

	simulation(nx, ny, direction, answer + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		A[a][b] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int a;
		char b;
		cin >> a >> b;
		m[a] = b;
	}
	
	body.push({ 1, 1 });

	simulation(1, 1, 1, 1);

	return 0;
}