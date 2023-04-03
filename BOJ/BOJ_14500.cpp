#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[500][500];
bool visited[500][500];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int maxValue;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void dfs(int x, int y, int depth, int sum) {
	if (depth == 4) {
		maxValue = max(maxValue, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, depth + 1, sum + board[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}

int check(int x, int y) {	// ㅗ 처리
	vector<int> udlr(4, 0);	// 상하좌우
	int sum = 0;
	if (!isOut(x, y - 1) && !isOut(x, y + 1)) {	// ㅡ
		sum = board[x][y - 1] + board[x][y] + board[x][y + 1];	
		if (!isOut(x - 1, y)) {	// ㅗ
			udlr[0] = sum + board[x - 1][y];
		}	
		if (!isOut(x + 1, y)) {	// ㅜ
			udlr[1] = sum + board[x + 1][y];
		}
	}
	if (!isOut(x - 1, y) && !isOut(x + 1, y)) {	// l
		sum = board[x - 1][y] + board[x][y] + board[x + 1][y];
		if (!isOut(x, y - 1)) {	// ㅓ
			udlr[2] = sum + board[x][y - 1];
		}
		if (!isOut(x, y + 1)) {	// ㅏ
			udlr[3] = sum + board[x][y + 1];
		}
	}

	return *max_element(udlr.begin(), udlr.end());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		maxValue = 0;
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, board[i][j]);
			visited[i][j] = false;
			answer = max(answer, max(maxValue, check(i, j)));
		}
	}

	cout << answer << '\n';

	return 0;
}