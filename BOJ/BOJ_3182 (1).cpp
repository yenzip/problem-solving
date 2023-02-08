/* DFS */
#include <bits/stdc++.h>

using namespace std;

int adj[1000 + 1];
bool visited[1000 + 1];
int cnt;

void dfs(int cur) {
	visited[cur] = true;
	cnt++;

	while (!visited[adj[cur]]) {
		dfs(adj[cur]);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int answer;
		cin >> answer;
		adj[i] = answer;
	}

	int max = 0, minIdx;
	for (int i = 0; i <= N; i++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));

		dfs(i);

		if (max < cnt) {
			max = cnt;
			minIdx = i;
		}
	}

	cout << minIdx;

	return 0;
}