#include <bits/stdc++.h>
using namespace std;

int T;
int m1, d1;
int m2, d2;
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> m1 >> d1 >> m2 >> d2;
		int answer = d2 - d1 + 1;
		for (int i = m1; i < m2; i++) {
			answer += days[i];
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}
