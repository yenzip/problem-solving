#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int A[101][101];
map<int, char> m;	// { ��, ���� }
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };	// �� - �� - �� - �� (�ð����)
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> body;	// ���� �� ��ǥ

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > N);
}

int turnDirection(char C, int direction) {
	if (C == 'L') {	// ���� 90�� ȸ��
		return (direction + 3) % 4;
	}
	else {			// ������ 90�� ȸ��
		return (direction + 1) % 4;
	}
}

void simulation(int x, int y, int direction, int answer) {

	int nx = x + dx[direction];
	int ny = y + dy[direction];

	if (isOut(nx, ny) || visited[nx][ny]) {	// ���̳� �ڽ��� ���� �΋H���� ���� ����
		cout << answer;
		return;
	}

	visited[nx][ny] = true;
	body.push({ nx, ny });

	if (A[nx][ny] == 1) {	// �̵��� ĭ�� ����� �ִٸ�
		A[nx][ny] = 0;
	}
	else {	// �̵��� ĭ�� ����� ���ٸ�, ����ĭ ����
		visited[body.front().first][body.front().second] = false;
		body.pop();
	}

	if (m.count(answer) != 0) {	// ���� ��ȯ
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