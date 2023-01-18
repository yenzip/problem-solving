#include <bits/stdc++.h>

using namespace std;

int main() {
	int v, e;	// v: 정점, e: 간선
	vector<vector<int>> adj;	// adj: 인접 리스트
	
	cin >> v >> e;

	adj.resize(v + 1);	// 1부터 시작하기 위해 (0 ~ v)

	for (int i = 0; i < e; i++) {
		int start, end;	// start: 시작점, end: 끝점
		cin >> start >> end;
		adj[start].push_back(end);
	}

	for (int i = 1; i <= v; i++) {	// 그래프 출력
		cout << "[" << i << "] : ";
		for (int v : adj[i]) {
			cout << "[" << v << "] ";
		}
		cout << '\n';
	}

	return 0;
}