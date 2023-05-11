#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[1001];

void dfs(int now) {
	visited[now] = true;

	for (auto next : graph[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			answer++;
		}
	}

	cout << answer;

	return 0;
}