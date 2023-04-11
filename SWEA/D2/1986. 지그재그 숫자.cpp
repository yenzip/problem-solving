#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << '#' << i << ' ';
		if (N % 2) {
			cout << -1 * (N - 1) / 2 + N << '\n';
		}
		else {
			cout << -1 * N / 2 << '\n';
		}
	}

	return 0;
}