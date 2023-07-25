#include <bits/stdc++.h>
using namespace std;

struct Point {
	int rx, ry;	// ���� ���� ��ǥ
	int bx, by;	// �Ķ� ���� ��ǥ
	int cnt;	// ����� Ƚ��
};

int N, M;
char A[10][10];
bool visited[10][10][10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

pair<int, int> tilt(int x, int y, int direction) {	// ����̱�
	if (A[x][y] == 'O') {	// ���� ������ ��ȯ
		return { x, y };
	}
	if (A[x][y] == '#') {	// ���� ������ �ڷ� ���ư���
		return { x - dx[direction], y - dy[direction] };
	}
	return tilt(x + dx[direction], y + dy[direction], direction);
}

int bfs(int rx, int ry, int bx, int by) {
	queue<Point> q;

	visited[rx][ry][bx][by] = true;
	q.push({ rx, ry, bx, by, 0 });

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) {	// ���� ������ ��ġ�� ������ �ƴϸ鼭 ����� Ƚ���� 10 �̻��̶�� ����
			return -1;
		}

		for (int i = 0; i < 4; i++) {
			pair<int, int> nr = tilt(rx, ry, i);	// ���� ���� ������
			int nrx = nr.first, nry = nr.second;
			pair<int, int> nb = tilt(bx, by, i);	// �Ķ� ���� ������
			int nbx = nb.first, nby = nb.second;

			if (A[nbx][nby] == 'O') {	// ����ó��: �Ķ� ���� ���� ���ۿ� ���������� ���
				continue;
			}
			if (A[nrx][nry] == 'O') {	// ���� ���� ���� ���ۿ� ������ ���
				return cnt + 1;	// ����� Ƚ�� ��ȯ
			}

			if (nrx == nbx && nry == nby) {	// ����̰� �� �� ���� ������ �Ķ� ������ ���� ��ġ�� �ִٸ�
				int dr = abs(nrx - rx) + abs(nry - ry);	// �̵��Ÿ� ��� �� �Ÿ��� �� �� ���� �ڷΰ���
				int db = abs(nbx - bx) + abs(nby - by);	

				if (dr > db) {	// ���� ���� �ڷΰ���
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {			// �Ķ� ���� �ڷΰ���
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int rx, ry, bx, by;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];

			if (A[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			if (A[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	cout << bfs(rx, ry, bx, by);

	return 0;
}