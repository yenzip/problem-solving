#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		reverse(s.begin(), s.end());
		string answer;
		for (auto c : s) {
			if (c == 'b') {
				answer += 'd';
			}
			else if (c == 'd') {
				answer += 'b';
			}
			else if (c == 'p') {
				answer += 'q';
			}
			else if (c == 'q') {
				answer += 'p';
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}