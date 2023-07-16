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

	int answer = 0;		// �湮�� ĭ�� ��
	int turnCnt = 0;	// ȸ�� Ƚ��

	while (true) {
		turnLeft();	// 1. ���� �������� ȸ��
		
		int nx = x + dx[direction];	
		int ny = y + dy[direction];

		if (!isOut(nx, ny) && A[nx][ny] == 0 && !visited[nx][ny]) {	// 2-1. �湮���� ���� ĭ ����
			visited[nx][ny] = true;
			answer++;
			x = nx;
			y = ny;
			turnCnt = 0;
			continue;
		}
		else {	// 2-2. ȸ���� �����ϰ� 1�ܰ�� ���ư�
			turnCnt++;
		}

		if (turnCnt == 4) {	// 3. 4 ���� ��� ���� ĭ�̰ų� �ٴ��� ���
			nx = x - dx[direction];	// ���� ������ ä 1�ܰ�� ���ư�
			ny = y - dy[direction];

			if (!isOut(nx, ny) && A[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			else {	// �ٴ� ĭ�� ��� ������ ����
				break;
			}
			
			turnCnt = 0;
		}
	}

	cout << answer;

	return 0;
}
