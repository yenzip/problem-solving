#include <bits/stdc++.h>
using namespace std;

struct CCTV {
	int x, y, num;
};

int N, M;
int A[8][8];
vector<CCTV> v;
int dx[4] = { -1, 0, 1, 0 };	// 시계방향
int dy[4] = { 0, 1, 0, -1 };
int rotation[6] = { 0, 4, 2, 4, 4, 1 };	// CCTV 별 회전 가능한 횟수
int answer;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void watch(int x, int y, int dir) {	// CCTV 감시하기
	dir %= 4;

	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isOut(nx, ny) || A[nx][ny] == 6) {
			return;
		}

		if (A[nx][ny] == 0) {
			A[nx][ny] = -1;
		}
		
		x = nx;
		y = ny;
	}
}

void copy(int A[8][8], int B[8][8]) {	// 강한 복사 B -> A
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = B[i][j];
		}
	}
}

int checkZero() {	// CCTV 사각지대 찾기
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!A[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

void dfs(int idx) {	// 백트래킹
	if (idx == v.size()) {
		answer = min(answer, checkZero());
		return;
	}

	int x = v[idx].x;
	int y = v[idx].y;
	int num = v[idx].num;
	int backup[8][8];

	for (int i = 0; i < rotation[num]; i++) {
		copy(backup, A);	// A 복사

		if (num == 1) {
			watch(x, y, i);
		}
		else if (num == 2) {
			watch(x, y, i);
			watch(x, y, i + 2);
		}
		else if (num == 3) {
			watch(x, y, i);
			watch(x, y, i + 1);
		}
		else if (num == 4) {
			watch(x, y, i);
			watch(x, y, i + 1);
			watch(x, y, i + 2);
		}
		else if (num == 5) {
			watch(x, y, i);
			watch(x, y, i + 1);
			watch(x, y, i + 2);
			watch(x, y, i + 3);
		}

		dfs(idx + 1);
		copy(A, backup);	// A 복원
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			
			if (A[i][j] > 0 && A[i][j] < 6) {
				v.push_back({ i, j, A[i][j] });
			}
		}
	}

	answer = 64;
	dfs(0);

	cout << answer;

	return 0;
}