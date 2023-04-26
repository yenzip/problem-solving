#include <bits/stdc++.h>
using namespace std;

int TC, N, M;
int snack[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> snack[i];
		}

		int answer = -1;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (snack[i] + snack[j] <= M) {
					answer = max(answer, snack[i] + snack[j]);
				}
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}
