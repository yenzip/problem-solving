#include <bits/stdc++.h>
using namespace std;

int N;
int W[10][10];
bool visited[10];
int answer = 10000000;

void dfs(int start, int now, int depth, int cost) {
	if (depth == N) {
		if (W[now][start]) {	// 시작점으로 돌아가는 경로가 존재하는 경우
			answer = min(answer, cost + W[now][start]);
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && W[now][i]) {
			visited[i] = true;
			dfs(start, i, depth + 1, cost + W[now][i]);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, i, 1, 0);
		visited[i] = false;
	}

	cout << answer << '\n';

	return 0;
}