#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[1000 + 1];

void bfs(int start) {
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << '\n';
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
	int v, e;
	cin >> v >> e;

	adj.resize(v + 1);
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	bfs(1);

	return 0;
}