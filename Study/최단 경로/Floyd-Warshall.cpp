#include <bits/stdc++.h>
using namespace std;

#define INF 100000
int V, E;
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
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = w;
	}

	for (int k = 1; k <= V; k++) {
		for (int a = 1; a <= V; a++) {
			for (int b = 1; b <= V; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (d[i][j] == INF) {
				cout << INF << " ";
			}
			else {
				cout << d[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}