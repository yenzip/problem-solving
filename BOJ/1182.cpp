#include <bits/stdc++.h>
using namespace std;

int N, S;
int A[20];
int answer;

void dfs(int idx, int sum) {
	if (idx == N) {
		return;
	}

	if (sum + A[idx] == S) {
		answer++;
	}
	
	dfs(idx + 1, sum);			// A[idx] 선택 X
	dfs(idx + 1, sum + A[idx]);	// A[idx] 선택 O
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dfs(0, 0);

	cout << answer;

	return 0;
}