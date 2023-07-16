#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int board[101][101];
map<int, char> m;	// { ��, ���� }
bool visited[101][101];
int dx[4] = { -1, 0, 1, 0 };	// �� - �� - �� - �� (�ð����)
int dy[4] = { 0, 1, 0, -1 };
int direction;

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > N);
}

void turnDirection(char c) {
	if (c == 'L') {	// �������� 90�� ȸ��
		direction -= 1;
		if (direction == -1) {
			direction = 3;
		}
	}
	else {	// ���������� 90�� ȸ��
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
		board[x][y] = 1;	// ����� ��ġ 1�� ǥ��
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int a;
		char b;
		cin >> a >> b;
		m[a] = b;	// ���� ���� ��ȯ ����
	}

	int answer = 0;
	int x = 1;
	int y = 1;

	queue<pair<int, int>> body;	// ���� �� ��ǥ
	body.push({ x, y });

	direction = 1;	// ���� ó���� ������(��)�� ���Ѵ�

	while (true) {
		answer++;

		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (isOut(nx, ny) || visited[nx][ny]) {	// �� �Ǵ� ���� �΋H���� ���� ����
			break;
		}

		visited[nx][ny] = true;
		body.push({ nx, ny });

		if (board[nx][ny] == 1) {	// �̵��� ĭ�� ����� �ִٸ�
			board[nx][ny] = 0;	// ��� ������
		}
		else {	// �̵��� ĭ�� ����� ���ٸ�
			visited[body.front().first][body.front().second] = false;	// ������ ��ġ�� ĭ ����ش�
			body.pop();
		}

		x = nx;
		y = ny;

		if (m.count(answer) != 0) {	// ���� ��ȯ
			turnDirection(m[answer]);
		}
	}

	cout << answer;

	return 0;
}