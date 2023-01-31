#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(v[i], v[j]);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}