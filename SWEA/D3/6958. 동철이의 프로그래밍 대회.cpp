#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A[20][20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		int maxVal = 0;
		for (int i = 0; i < N; i++) {
			int count = 0;
			for (int j = 0; j < M; j++) {
				cin >> A[i][j];
				A[i][j] ? count += 1 : count;
			}
			maxVal = max(maxVal, count);
		}

		int winner = 0;
		for (int i = 0; i < N; i++) {
			int tmp = accumulate(A[i], A[i] + M, 0);
			if (tmp == maxVal) {
				winner++;
			}
		}
		cout << '#' << t << ' ' << winner << ' ' << maxVal << '\n';
	}

	return 0;
}