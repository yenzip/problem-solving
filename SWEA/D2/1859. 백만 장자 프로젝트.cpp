#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		long long answer = 0;
		int maxVal = A[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			if (A[i] > maxVal) {
				maxVal = A[i];
			}
			else {
				answer += maxVal - A[i];
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}