#include <bits/stdc++.h>
using namespace std;

int T;
int side[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 3; i++) {
			cin >> side[i];
		}
		sort(side, side + 3);
		int answer = 0;
		if (side[0] == side[1]) {
			answer = side[2];
		}
		else if (side[1] == side[2]) {
			answer = side[0];
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}