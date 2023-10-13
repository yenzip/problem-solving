#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int A[20];
int answer;

void dfs(int idx, int sum) {
	if (sum > K) {
		return;
	}
	if (sum == K) {
		answer++;
		return;
	}

	for (int i = idx; i < N; i++) {
		dfs(i + 1, sum + A[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		answer = 0;
		dfs(0, 0);

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}