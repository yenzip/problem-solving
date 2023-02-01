#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
vector<vector<int>> adj;
bool visited[MAX + 1] = { false, };

void dfs(int cur) {
	visited[cur] = true;
	cout << cur << ' ';

	for (int next : adj[cur]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
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
	int N, M, V;
	cin >> N >> M >> V;

	adj.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V);
	cout << '\n';

	memset(visited, false, sizeof(visited));
	bfs(V);

	return 0;
}