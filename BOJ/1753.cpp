#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> graph;
vector<int> D;

void dijsktra(int s) {
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

	cin >> V >> E >> K;
	graph.resize(V + 1);
	D.resize(V + 1, INF);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	dijsktra(K);

	for (int i = 1; i <= V; i++) {
		if (D[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << D[i] << "\n";
		}
	}

	return 0;
}