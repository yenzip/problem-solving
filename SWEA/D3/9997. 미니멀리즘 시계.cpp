#include <bits/stdc++.h>
using namespace std;

int T;
int angle;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> angle;
		int hour = angle / (360 / 12);
		int min = angle % (360 / 12) * 2;
		cout << '#' << t << ' ' << hour << ' ' << min << '\n';
	}

	return 0;
}