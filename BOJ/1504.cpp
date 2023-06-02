#include <bits/stdc++.h>
#define INF 98765432
using namespace std;

int N, E;
vector<pair<int, int>> graph[801];
int D[801];
int V1, V2;

void dijsktra(int start) {
	memset(D, INF, sizeof(D));

	priority_queue<pair<int, int>> pq;
	D[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dist > D[now]) {
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

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	cin >> V1 >> V2;



	int S_V1, V1_V2, V2_E;		// 1. 1 -> V1 -> V2 -> N
	int S_V2, V1_E;				// 2. 1 -> V2 -> V1 -> N	

	dijsktra(1);
	S_V1 = D[V1];
	S_V2 = D[V2];

	dijsktra(V1);
	V1_V2 = D[V2];
	V1_E = D[N];

	dijsktra(V2);
	V2_E = D[N];

	int answer = min(INF, min(S_V1 + V1_V2 + V2_E, S_V2 + V1_V2 + V1_E));
	if (answer >= INF) {
		cout << -1;
	}
	else {
		cout << answer;
	}

	return 0;
}