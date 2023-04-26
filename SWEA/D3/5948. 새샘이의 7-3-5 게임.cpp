#include <bits/stdc++.h>
using namespace std;

int T;
int a[7];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 7; i++) {
			cin >> a[i];
		}

		vector<int> idx(7, 0);
		for (int i = 4; i < 7; i++) {
			idx[i] = 1;
		}

		vector<int> result;
		do {
			int sum = 0;
			for (int i = 0; i < 7; i++) {
				if (idx[i]) {
					sum += a[i];
				}
			}
			if (find(result.begin(), result.end(), sum) == result.end()) {
				result.push_back(sum);
			}

		} while (next_permutation(idx.begin(), idx.end()));

		sort(result.rbegin(), result.rend());

		cout << '#' << t << ' ' << result[4] << '\n';
	}

	return 0;
}