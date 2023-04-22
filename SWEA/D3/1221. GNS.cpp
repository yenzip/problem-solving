#include <bits/stdc++.h>
using namespace std;

int T, N;
string seq;
vector<string> number = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> seq >> N;
		string idx;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			idx += to_string(find(number.begin(), number.end(), s) - number.begin());
		}
		sort(idx.begin(), idx.end());
		cout << '#' << t << '\n';
		for (int i = 0; i < N; i++) {
			cout << number[idx[i] - '0'] << ' ';
		}
		cout << '\n';
	}

	return 0;
}