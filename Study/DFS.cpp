#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;	// adj: 인접 리스트
bool isVisited[1000 + 1];		// isVisited: 방문 여부

void dfs(int cur) {	// cur : 현재 정점
	if (isVisited[cur]) {	// 정점 모두 방문 시 return
		return;
	}

	isVisited[cur] = true;	// 현재 정점 방문
	cout << "[" << cur << "] ";	// 정점 출력
		
	for (int next : adj[cur]) {	// 최근 방문한 정점에 인접한 정점 방문
		dfs(next);
	}
}

int main() {
	int v, e;	// v : 정점, e : 간선

	cin >> v >> e;

	adj.resize(v + 1);	// 0 ~ v
	memset(isVisited, false, sizeof(isVisited));	// 0 ~ v

	for (int i = 0; i < e; i++) {	// 그래프 구현
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
	}

	dfs(1);	// 깊이우선탐색

	return 0;
}