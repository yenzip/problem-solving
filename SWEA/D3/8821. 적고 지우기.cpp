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
		int num[10] = { 0 };
		for (auto c : s) {
			if (!num[c - '0']) {
				num[c - '0']++;
			}
			else {
				num[c - '0']--;
			}
		}
		
		int answer = 0;
		for (int i = 0; i < 10; i++) {
			if (num[i]) {
				answer += num[i];
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}
	
	return 0;
}