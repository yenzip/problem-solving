#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y, d;
int A[50][50];
bool visited[50][50];
int dx[4] = { -1, 0, 1, 0 };	// �� - �� - �� - �� (�ð����)
int dy[4] = { 0, 1, 0, -1 };
int answer;

void simulation(int x, int y, int direction) {
	if (!visited[x][y] && A[x][y] == 0) {	// 1. ���� ĭ û��
		visited[x][y] = true;
		answer++;
	}

	int curDirection = direction;

	for (int i = 0; i < 4; i++) {
		int nextDirection = (curDirection + 3) % 4;
		int nx = x + dx[nextDirection];
		int ny = y + dy[nextDirection];

		if (!visited[nx][ny] && A[nx][ny] == 0) {	// 3. �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ ����
			simulation(nx, ny, nextDirection);
			return;
		}

		curDirection = nextDirection;
	}

	int nx = x - dx[curDirection];	// 2. �ֺ� 4ĭ �� û�ҵ��� ���� ��ĭ�� ���� ���
	int ny = y - dy[curDirection];	// �ٶ󺸴� ������ ������ ä�� ����

	if (A[nx][ny] == 1) {	//	������ �� ���ٸ� �۵� ����
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