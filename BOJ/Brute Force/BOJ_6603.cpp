#include <bits/stdc++.h>
using namespace std;

int k;
int S[13];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> k;

		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}

		vector<int> idx(k, 0);
		for (int i = 0; i < 6; i++) {
			idx[i] = 1;
		}

		do {
			for (int i = 0; i < k; i++) {
				if (idx[i] == 1) {
					cout << S[i] << ' ';
				}
			}
			cout << '\n';
		} while (prev_permutation(idx.begin(), idx.end()));

		cout << '\n';
	}

	return 0;
}