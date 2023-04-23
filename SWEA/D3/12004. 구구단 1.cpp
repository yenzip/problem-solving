#include <bits/stdc++.h>
using namespace std;

int TC, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		string answer = "No";
		for (int i = 1; i <= 9; i++) {
			if (N % i == 0) {
				int b = N / i;
				if (b >= 1 && b <= 9) {
					answer = "Yes";
					break;
				}
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}
