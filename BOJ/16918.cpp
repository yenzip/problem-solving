#include <bits/stdc++.h>
using namespace std;

int R, C, N;
char A[200][200];
int Time[200][200];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void setBomb(int sec) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] == '.') {
				A[i][j] = 'O';
				Time[i][j] = sec + 3;
			}
		}
	}
}

bool isOut(int x, int y) {
	return (x < 0 || x >= R || y < 0 || y >= C);
}

void bomb(int sec) {
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (Time[x][y] != sec) {
				continue;
			}

			A[x][y] = '.';
			Time[x][y] = 0;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!isOut(nx, ny) && A[nx][ny] == 'O') {
					A[nx][ny] = '.';
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'O') {
				Time[i][j] = 3;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0) {
			setBomb(i);
		}
		else {
			bomb(i);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}

	return 0;
}