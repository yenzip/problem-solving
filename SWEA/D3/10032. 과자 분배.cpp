#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		int answer = N % K == 0 ? 0 : 1;
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}