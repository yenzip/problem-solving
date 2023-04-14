#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		int answer;
		if (A >= 10 || B >= 10) {
			answer = -1;
		}
		else {
			answer = A * B;
		}
		cout << '#' << t << ' ' << answer << '\n';
	}
}