#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		long long answer = -1;
		if (x == y) {
			answer = x;
		}
		else {
			if (M <= N) {
				vector<int> v(N);
				v[0] = x;
				for (int i = 1; i < N; i++) {
					v[i] = (v[i - 1] + M) % N;	
					v[i] == 0 ? v[i] = N : v[i];	// 0 贸府
					if (v[i] == y) {
						answer = i * M + x;
						break;
					}
				}
			}
			else {
				vector<int> v(M);
				v[0] = y;
				for (int i = 1; i < M; i++) {
					v[i] = (v[i - 1] + N) % M;	
					v[i] == 0 ? v[i] = M : v[i];	// 0 贸府
					if (v[i] == x) {
						answer = i * N + y;
						break;
					}
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}