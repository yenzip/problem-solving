#include <bits/stdc++.h>
using namespace std;

int TC;
string S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> S;
		map<char, int> m;
		for (auto c : S) {
			m[c]++;
		}
		string answer = "Yes";
		for (auto i : m) {
			if (i.second != 2) {
				answer = "No";
				break;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}