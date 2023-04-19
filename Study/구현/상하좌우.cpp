#include <bits/stdc++.h>
using namespace std;

int N;
string movement;

bool isOut(int x, int y) {
	return (x < 1 || x > N || y < 1 || y > N);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin.ignore();
	getline(cin, movement);

	int x = 1, y = 1;
	for (auto c : movement) {
		if (c == ' ') {
			continue;
		}

		int nx = x, ny = y;
		if (c == 'L') {
			ny -= 1;
		}
		if (c == 'R') {
			ny += 1;
		}
		if (c == 'U') {
			nx -= 1;
		}
		if (c == 'D') {
			nx += 1;
		}

		if (!isOut(nx, ny)) {
			x = nx, y = ny;
		}
	}

	cout << x << ' ' << y << '\n';

	return 0;
}