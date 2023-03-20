#include <bits/stdc++.h>
using namespace std;

#define INF 30001
int N, M, C;
vector<vector<pair<int, int>>> graph;
int d[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
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

	cin >> N >> M >> C;

	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		graph[X].push_back({ Y, Z });
	}

	memset(d, INF, sizeof(d));
	dijkstra(C);

	int count = 0;
	int maxDist = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] != INF) {
			count++;
			maxDist = max(maxDist, d[i]);
		}
	}

	cout << count - 1 << " " << maxDist << "\n";

	return 0;
}