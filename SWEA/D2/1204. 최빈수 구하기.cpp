#include <bits/stdc++.h>
using namespace std;

int T;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int tc;
		cin >> tc;
		map<int, int> m;
		int score;
		for (int i = 0; i < 1000; i++) {
			cin >> score;
			m[score]++;
		}
		vector<pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), comp);
		cout << '#' << t << ' ' << v[0].first << '\n';
	}

	return 0;
}