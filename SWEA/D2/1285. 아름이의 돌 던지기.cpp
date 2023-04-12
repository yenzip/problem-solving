#include <bits/stdc++.h>
using namespace std;

int T, N;
int dist[100000 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(dist, 0, sizeof(dist));
		int minVal = 100000;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			minVal = min(minVal, abs(num));
			dist[abs(num)]++;
		}
		cout << '#' << t << ' ' << minVal << ' ' << dist[minVal] << '\n';
  	}

	return 0;
}