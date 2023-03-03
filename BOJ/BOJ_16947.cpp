#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> adj;
bool visited[3000 + 1];
int start;
bool isCycle[3000 + 1];

void dfs(int cur, int depth) {
	visited[cur] = true;

	for (int next : adj[cur]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
		else if (next == start && depth >= 2) {
			isCycle[start] = true;
			return;
		}
	}
}

int bfs(int s) {
	queue<pair<int, int>> q;

	visited[s] = true;
	q.push({ s, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (isCycle[cur]) {
			return dist;
		}

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	adj.resize(N + 1);
	memset(isCycle, false, sizeof(isCycle));

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		start = i;
		dfs(i, 0);	// 싸이클 정점 확인
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		cout << bfs(i) << " ";	// 정점 - 싸이클 거리 확인
	}

	return 0;
}