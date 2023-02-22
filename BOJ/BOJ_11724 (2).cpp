#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;
bool visited[1000 + 1];

void bfs(int start) {
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	adj.resize(N + 1);
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}