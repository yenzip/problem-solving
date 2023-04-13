#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S;
		string answer;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
				continue;
			}
			else {
				answer += S[i];
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}