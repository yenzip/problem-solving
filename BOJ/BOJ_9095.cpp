#include <bits/stdc++.h>

using namespace std;

int d[11 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	d[0] = 1;
	for (int i = 1; i <= 11; i++) {
		d[i] += d[i - 1];
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << d[N] << '\n';
	}

	return 0;
}