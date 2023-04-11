#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> A(20);
vector<int> B(20);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		int maxVal = -1e9;
		if (N <= M) {
			for (int i = 0; i <= M - N; i++) {
				int tmp = 0;
				for (int j = 0; j < N; j++) {
					tmp += A[j] * B[i + j];
				}
				maxVal = max(maxVal, tmp);
			}
		}
		else {
			for (int i = 0; i <= N - M; i++) {
				int tmp = 0;
				for (int j = 0; j < M; j++) {
					tmp += B[j] * A[i + j];
				}
				maxVal = max(maxVal, tmp);
			}
		}
		cout << '#' << i << ' ' << maxVal << '\n';
 	}

	return 0;
}