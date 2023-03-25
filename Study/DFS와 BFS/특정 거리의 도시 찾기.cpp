#include <bits/stdc++.h>
using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
int dist[300000 + 1];

void bfs(int start) {
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : graph[now]) {
			if (dist[next] == -1) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K >> X;

	graph.resize(N + 1);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	bfs(X);

	bool check = false;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << '\n';
			check = true;
		}
	}
	if (!check) {
		cout << -1 << '\n';
	}

	return 0;
}