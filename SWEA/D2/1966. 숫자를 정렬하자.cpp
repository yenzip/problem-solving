#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[50];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A, A + N);
		cout << '#' << t << ' ';
		for (int i = 0; i < N; i++) {
			cout << A[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}