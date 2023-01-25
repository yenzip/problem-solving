#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	vector<string> v;

	cin >> S;

	v.resize(S.size(), "");

	for (int i = 0; i < S.size(); i++) {
		v[i] += S.substr(i, S.size());
	}

	sort(v.begin(), v.end());

	for (string s : v) {
		cout << s << endl;
	}

	return 0;
}