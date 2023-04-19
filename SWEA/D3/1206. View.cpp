#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000];

bool check(int x) {
	int maxVal = *max_element(A + x - 2, A  + x + 2);
	return maxVal == A[x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 1; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		int answer = 0;
		for (int i = 2; i < N - 2; i++) {
			if (check(i)) {
				int max2 = max(max(A[i - 2], A[i - 1]), max(A[i + 1], A[i + 2]));
				answer += A[i] - max2;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}