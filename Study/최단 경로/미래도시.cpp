#include <bits/stdc++.h>
using namespace std;

#define INF 101
int V, E;
int X, K;
vector<vector<int>> d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	
	d.resize(V + 1, vector<int>(V + 1, INF));
	for (int i = 1; i <= V; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}
	cin >> X >> K;

	for (int k = 1; k <= V; k++) {	// Floyd-Warshall
		for (int a = 1; a <= V; a++) {
			for (int b = 1; b <= V; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}

	int dist = d[1][K] + d[K][X];
	dist == INF ? cout << -1 : cout << dist;

	return 0;
}