#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[21][21];
int dice[6] = { 1, 6, 2, 5, 3, 4 };	// ��(0), �Ʒ�(1), ��(2), ��(3), ��(4), ��(5)
bool visited[21][21];
int dx[4] = { -1, 0, 1, 0 };	// �� - �� - �� - �� (�ð����)
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
	if (direction == 0) {	// ������ ȸ��
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	if (direction == 1) {	// ������ ȸ��
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
	if (direction == 2) {	// ������ ȸ��
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	if (direction == 3) {	// ���� ȸ��
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

	int answer = 0;	// ������ �� ���ϱ�
	int x = 1, y = 1;
	int direction = 1;	// ó�� �ֻ��� �̵� ������ ����

	while (K--) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (isOut(nx, ny)) {	// 1. �̵� ���⿡ ĭ�� ���ٸ� �̵� ������ �ݴ��
			direction = (direction + 2) % 4;
			nx = x + dx[direction];
			ny = y + dy[direction];
		}

		rollDice(direction);	// 1. �ֻ��� ������

		int B = A[nx][ny];
		int C = bfs(nx, ny, B);	// 2. ���� ȹ��
		answer += B * C;

		if (dice[1] > B) {		// 3. �ֻ��� �Ʒ���(A)�� B ���� �̵����� ����
			direction = (direction + 1) % 4;	// �ð� ���� ȸ��
		}
		else if (dice[1] < B) {
			direction = (direction + 3) % 4;	// �ݽð� ���� ȸ��
		}

		x = nx;
		y = ny;
	}

	cout << answer;

	return 0;
}