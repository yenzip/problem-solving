#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> p;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x, y });
	}

	sort(p.begin(), p.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << p[i].first << " " << p[i].second << "\n";
	}

	return 0;
}