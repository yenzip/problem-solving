#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<bool> A(N + 1, true);
	A[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (A[i]) {
			for (int j = i * 2; j <= N; j += i) {
				A[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (A[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}