#include <bits/stdc++.h>
using namespace std;

int T, N, A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> A >> B;
		int maxVal = min(A, B);
		int minVal = A + B <= N ? 0 : A + B - N;
		cout << '#' << t << ' ' << maxVal << ' ' << minVal << '\n';
	}

	return 0;
}