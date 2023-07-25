#include <bits/stdc++.h>
using namespace std;

struct Point {
	int rx, ry;	// 빨간 구슬 좌표
	int bx, by;	// 파란 구슬 좌표
	int cnt;	// 기울임 횟수
};

int N, M;
char A[10][10];
bool visited[10][10][10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

pair<int, int> tilt(int x, int y, int direction) {	// 기울이기
	if (A[x][y] == 'O') {	// 구멍 만나면 반환
		return { x, y };
	}
	if (A[x][y] == '#') {	// 벽을 만나면 뒤로 돌아가기
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

		if (cnt >= 10) {	// 빨간 구슬의 위치가 구멍이 아니면서 기울임 횟수가 10 이상이라면 중지
			return -1;
		}

		for (int i = 0; i < 4; i++) {
			pair<int, int> nr = tilt(rx, ry, i);	// 빨간 구슬 기울어짐
			int nrx = nr.first, nry = nr.second;
			pair<int, int> nb = tilt(bx, by, i);	// 파란 구슬 기울어짐
			int nbx = nb.first, nby = nb.second;

			if (A[nbx][nby] == 'O') {	// 예외처리: 파란 구슬 먼저 구멍에 빠져나오는 경우
				continue;
			}
			if (A[nrx][nry] == 'O') {	// 빨간 구슬 먼저 구멍에 빠지는 경우
				return cnt + 1;	// 기울임 횟수 반환
			}

			if (nrx == nbx && nry == nby) {	// 기울이고 난 후 빨간 구슬과 파란 구슬이 같은 위치에 있다면
				int dr = abs(nrx - rx) + abs(nry - ry);	// 이동거리 계산 후 거리가 더 긴 구슬 뒤로가기
				int db = abs(nbx - bx) + abs(nby - by);	

				if (dr > db) {	// 빨간 구슬 뒤로가기
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {			// 파란 구슬 뒤로가기
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