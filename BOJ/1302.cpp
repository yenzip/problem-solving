#include <bits/stdc++.h>
using namespace std;

int N;
string title;
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> title;
		m[title]++;
		cnt = max(cnt, m[title]);
	}

	for (auto &entry : m) {
		if (entry.second == cnt) {
			cout << entry.first;
			break;
		}
	}

	return 0;
}