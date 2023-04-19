#include <bits/stdc++.h>
using namespace std;

int T, N, D;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> D;
		int answer = N / (2 * D + 1);
		if (N % (2 * D + 1)) {
			answer++;
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}