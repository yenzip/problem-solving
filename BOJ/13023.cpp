#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[2000];
int answer = 0;

void dfs(int now, int depth) {
	if (depth == 4) {
		answer = 1;
		return;
	}

	visited[now] = true;
	for (auto next : graph[now]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
	visited[now] = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	graph.resize(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 0);
		if (answer) {
			break;
		}
	}
	cout << answer << '\n';

	return 0;
}