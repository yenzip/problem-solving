#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int answer = N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A, A + N);
		for (int i = 0; i < N - 1; i++) {
			answer += A[i];
		}
		answer += A[N - 1] * 2;
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}