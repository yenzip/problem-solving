#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
bool visited[100001];
vector<int> parents;

void dfs(int now) {
	visited[now] = true;

	for (auto next : graph[now]) {
		if (!visited[next]) {
			parents[next] = now;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	parents.resize(N + 1, 0);
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parents[i] << "\n";
	}

	return 0;
}