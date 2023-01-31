#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	check[0] = check[1] = true;
	for (int i = 2; i <= MAX; i++) {
		if (!check[i]) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int ans = 0;
		for (int i = 2; i <= N/2; i++) {
			if (!check[i] && !check[N-i]) {
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}