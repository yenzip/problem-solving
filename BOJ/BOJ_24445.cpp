#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
vector<vector<int>> adj;
bool visited[MAX + 1] = { false, };
int visitedOrder[MAX + 1] = { 0, };
int order = 1;

void bfs(int start) {
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		visitedOrder[cur] = order++;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	adj.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].rbegin(), adj[i].rend());
	}

	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visitedOrder[i] << '\n';
	}

	return 0;
}