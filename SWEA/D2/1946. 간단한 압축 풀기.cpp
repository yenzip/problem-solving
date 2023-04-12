#include <bits/stdc++.h>
using namespace std;

int T, N, K;
char C;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		string s;
		for (int i = 0; i < N; i++) {
			cin >> C >> K;
			s += string(K, C);
		}
		cout << '#' << t << '\n';
		for (int i = 0; i < s.size(); i += 10) {
			cout << s.substr(i, 10) << '\n';
		}
	}

	return 0;
}