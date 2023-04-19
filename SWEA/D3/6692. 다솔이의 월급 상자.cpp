#include <bits/stdc++.h>
using namespace std;

int T, N;
double p, x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		double answer = 0;
		for (int i = 0; i < N; i++) {
			cin >> p >> x;
			answer += (p * x);
		}
		cout << '#' << t << ' ' << fixed << setprecision(6) << answer << '\n';
	}

	return 0;
}