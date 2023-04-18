#include <bits/stdc++.h>
using namespace std;

int T;
string N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		string answer = (N[N.size() - 1] - '0') % 2 ? "Odd" : "Even";
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}