#include <bits/stdc++.h>
using namespace std;

int T, n;
string clothe, type;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> n;

		map<string, int> m;

		for (int i = 0; i < n; i++) {
			cin >> clothe >> type;
			m[type]++;
		}

		int answer = 1;

		for (auto &entry : m) {
			answer *= (entry.second + 1);
		}

		cout << answer - 1 << "\n";
	}

	return 0;
}