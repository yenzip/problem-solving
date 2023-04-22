#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		string answer;
		vector<string> v(5);
		int maxSize = 0;
		for (int i = 0; i < 5; i++) {
			cin >> v[i];
			if (maxSize < v[i].size()) {
				maxSize = v[i].size();
			}
		}
		for (int j = 0; j < maxSize; j++) {
			for (int i = 0; i < 5; i++) {
				if (v[i].size() > j) {
					answer += v[i][j];
				}
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}