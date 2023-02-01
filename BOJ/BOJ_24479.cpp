#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool isVisited[100000 + 1];
int visitedOrder[100000 + 1] = { 0, };
int order = 1;

void dfs(int cur) {
	isVisited[cur] = true;
	visitedOrder[cur] = order++;
	
	for (int next : adj[cur]) {
		if (!isVisited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	adj.resize(N + 1);
	memset(isVisited, false, sizeof(isVisited));

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visitedOrder[i] << '\n';
	}

	return 0;
}