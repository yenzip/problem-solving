#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[49][49];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < N; j++) {
				A[i][j] = line[j] - '0';
			}
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (N / 2 - i >= 0) {
				for (int j = N / 2 - i; j <= N / 2 + i; j++) {
					answer += A[i][j];
				}
			}
			else {
				for (int j = i - N / 2; j < N - i + N / 2; j++) {
					answer += A[i][j];
				}
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}
	
	return 0;
}