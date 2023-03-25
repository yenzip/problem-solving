#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int n, m;
vector<vector<int>> d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	d.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= n; k++) {	// Floyd-Warshall
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << d[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}