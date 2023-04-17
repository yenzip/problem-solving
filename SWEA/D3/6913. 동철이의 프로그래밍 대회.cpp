#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int correct[20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		int maxVal = 0;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < M; j++) {
				int num;
				cin >> num;
				num ? cnt++ : cnt;
			}
			correct[i] = cnt;
			maxVal = max(maxVal, cnt);
		}

		int winner = 0;
		for (int i = 0; i < N; i++) {
			if (correct[i] == maxVal) {
				winner++;
			}
		}
		cout << '#' << t << ' ' << winner << ' ' << maxVal << '\n';
	}

	return 0;
}