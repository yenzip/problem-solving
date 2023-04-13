#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int go(int n, int m) {
	if (m == 1) {
		return n;
	}
	return n * go(n, m-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		cin >> T >> N >> M;
		cout << '#' << t << ' ' << go(N, M) << '\n';
	}

	return 0;
}