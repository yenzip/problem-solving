#include <bits/stdc++.h>
using namespace std;

int t, n;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		int A[100];
		
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		long long answer = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				answer += GCD(A[i], A[j]);
			}
		}

		cout << answer << "\n";
	}
}