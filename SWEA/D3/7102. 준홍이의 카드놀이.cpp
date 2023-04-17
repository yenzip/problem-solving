#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int sum[41];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				sum[i + j]++;
			}
		}
		cout << '#' << t << ' ';
		int maxVal = *max_element(sum, sum + N + M);
		for (int i = 1; i <= N + M; i++) {
			if (sum[i] == maxVal) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}