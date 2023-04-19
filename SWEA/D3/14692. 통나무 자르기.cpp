#include <bits/stdc++.h>
using namespace std;

int TC, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		string answer = N % 2 ? "Bob" : "Alice";
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}