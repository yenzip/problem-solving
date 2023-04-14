#include <bits/stdc++.h>
using namespace std;

int T, K;
int A[1024];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K;
		int answer = 0;
		int n = pow(2, K);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		while (n != 1) {
			int idx = 0;
			int tmp[1024];
			for (int i = 0; i < n - 1; i += 2) {
				answer += abs(A[i] - A[i + 1]);
				tmp[idx++] = max(A[i], A[i + 1]);
			}
			copy(tmp, tmp + n, A);
			n = idx;
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}