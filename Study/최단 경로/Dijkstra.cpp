#include <bits/stdc++.h>
using namespace std;

#define INF 100000
int V, E;
int start;
vector<vector<pair<int, int>>> graph;
int d[100000 + 1];

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	d[s] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) {
			continue;
		}

		for (auto next : graph[now]) {
			int cost = dist + next.second;
			if (cost < d[next.first]) {
				d[next.first] = cost;
				pq.push({ -cost, next.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	cin >> start;

	graph.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	fill(d, d + 100001, INF);
	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INFINITY" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}