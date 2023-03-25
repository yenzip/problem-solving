#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;	// adj: 인접 리스트
bool visited[1000 + 1];		// visited: 방문 여부

void dfs(int cur) {
	visited[cur] = true;	// 현재 정점 방문	
	cout << cur << '\n';	// 정점 출력

	for (int next : adj[cur]) {	// 최근 방문한 정점에 인접한 정점 방문
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	int v, e;	// v : 정점, e : 간선
	cin >> v >> e;

	adj.resize(v + 1);	// 0 ~ v
	memset(visited, false, sizeof(visited));	// 0 ~ v

	for (int i = 0; i < e; i++) {	// 그래프 구현
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	dfs(1);	// 깊이우선탐색

	return 0;
}