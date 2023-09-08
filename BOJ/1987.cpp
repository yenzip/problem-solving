#include <bits/stdc++.h>
using namespace std;

int R, C;
char A[20][20];
bool visited[26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer = 0;

bool isOut(int x, int y) {
	return (x < 0 || x >= R || y < 0 || y >= C);
}

void dfs(int x, int y, int cnt) {
	answer = max(answer, cnt);
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && !visited[A[nx][ny] - 'A']) {
			visited[A[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			visited[A[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
		}
	}

	visited[A[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << answer;

	return 0;
}