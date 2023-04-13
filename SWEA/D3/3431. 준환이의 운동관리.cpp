#include <bits/stdc++.h>
using namespace std;

int T, L, U, X;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> L >> U >> X;
		int answer = 0;
		if (X < L) {
			answer = L - X;
		}
		else if (X > U) {
			answer = -1;
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}