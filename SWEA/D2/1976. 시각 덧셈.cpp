#include <bits/stdc++.h>
using namespace std;

int T;
int h1, m1;
int h2, m2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> h1 >> m1 >> h2 >> m2;
		int h = h1 + h2;
		int m = m1 + m2;
		if (m >= 60) {
			m -= 60;
			h++;
		}
		if (h > 12) {
			h -= 12;
		}
		
		cout << '#' << t << ' ' << h << ' ' << m << '\n';
 	}

	return 0;
}