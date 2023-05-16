#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> D;

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	D[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (D[now] < dist) {
			continue;
		}

		for (auto next : graph[now]) {
			int cost = dist + next.second;
			if (cost < D[next.first]) {
				D[next.first] = cost;
				pq.push({ -cost, next.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	graph.resize(N + 1);
	D.resize(N + 1, INT_MAX);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	int s, e;
	cin >> s >> e;

	dijkstra(s);

	cout << D[e];

	return 0;
}