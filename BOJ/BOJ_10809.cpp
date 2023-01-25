#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	vector<int> v(26, -1);

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		char c = S[i];

		if (v[c - 'a'] == -1) {
			v[c - 'a'] = i;
		}
	}

	for (int n : v) {
		cout << n << ' ';
	}

	return 0;
}