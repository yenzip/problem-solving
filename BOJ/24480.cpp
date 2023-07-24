#include <bits/stdc++.h>
using namespace std;

int N, M, R, u, v;
vector<vector<int>> graph;
bool visited[100001];
int answer[100001];
int seq;

void dfs(int x) {
	visited[x] = true;
	answer[x] = seq++;

	for (int next : graph[x]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;

	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].rbegin(), graph[i].rend());
	}

	seq = 1;
	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}