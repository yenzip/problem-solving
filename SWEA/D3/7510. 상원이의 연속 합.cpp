#include <bits/stdc++.h>
using namespace std;

int T, N;

bool check(int n) {
	int sum = 0;
	for (int i = n; i <= N; i++) {
		sum += i;
		if (sum == N) {
			return true;
		}
		else if (sum > N) {
			return false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (check(i)) {
				answer++;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}