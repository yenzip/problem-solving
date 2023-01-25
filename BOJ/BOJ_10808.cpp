#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	vector<int> v(26, 0);

	cin >> S;

	for (char c : S) {
		v[c - 'a']++;
	}

	for (int n : v) {
		cout << n << ' ';
	}

	return 0;
}