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
			if (find(S.begin() + i + 1, S.end(), S[i]) != S.end()) {
				int idx = find(S.begin() + i + 1, S.end(), S[i]) - S.begin();
				S[i] = S[idx] = ' ';
			}
			else if(S[i] != ' ') {
				answer += S[i];
			}
		}
		if (answer.empty()) {
			answer = "Good";
		}
		else {
			sort(answer.begin(), answer.end());
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}