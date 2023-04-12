#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A[15][15];

int check(int x, int y) {
	int sum = 0;
	for (int i = x; i < x + M; i++) {
		for (int j = y; j < y + M; j++) {
			sum += A[i][j];
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i <= N - M; i++) {
			for (int j = 0; j <= N - M; j++) {
				answer = max(answer, check(i, j));
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}