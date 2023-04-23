#include <bits/stdc++.h>
using namespace std;

int T, H;
string S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S >> H;
		vector<string> hypen(100);
		for (int i = 0; i < H; i++) {
			int idx;
			cin >> idx;
			hypen[idx].push_back('-');
		}
		string answer;
		for (int i = 0; i < S.size(); i++) {
			answer += hypen[i];
			answer += S[i];
		}
		answer += hypen[S.size()];
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}