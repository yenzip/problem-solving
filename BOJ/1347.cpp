#include <bits/stdc++.h>
using namespace std;

int N;
string path;
char A[101][101];	// 미로
bool visited[101][101];
int dx[4] = { -1,0, 1, 0 };	// 북 - 동 - 남 - 서 (시계방향)
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> path;

	memset(A, '#', sizeof(A));

	int x = 50, y = 50;
	int direction = 2;
	int sx = x, sy = y;
	int ex = x, ey = y;

	A[x][y] = '.';

	for (auto c : path) {
		if (c == 'F') {
			x = x + dx[direction];
			y = y + dy[direction];
			A[x][y] = '.';
			sx = min(sx, x);
			sy = min(sy, y);
			ex = max(ex, x);
			ey = max(ey, y);
		}
		else if (c == 'L') {	// 왼쪽 90도 회전
			direction = (direction + 3) % 4;
		}
		else {	// 오른쪽 90도 회전
			direction = (direction + 1) % 4;
		}
	}

	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			cout << A[i][j];
		}
		cout << "\n";
	}

	return 0;
}