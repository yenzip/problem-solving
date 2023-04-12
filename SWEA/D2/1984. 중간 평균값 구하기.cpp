#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int A[10];
		for (int i = 0; i < 10; i++) {
			cin >> A[i];
		}
		sort(A, A + 10);
		double sum = 0;
		for (int i = 1; i < 9; i++) {
			sum += A[i];
		}
		cout << '#' << t << ' ' << round(sum / 8) << '\n';
	}

	return 0;
}