#include <bits/stdc++.h>
using namespace std;

int T, N;

int check(int n) {
	set<int> s;
	while (n) {
		s.insert(n % 10);
		n /= 10;
	}
	return s.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << '#' << t << ' ' << check(N) << '\n';
	}

	return 0;
}