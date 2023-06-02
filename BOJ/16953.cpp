#include <bits/stdc++.h>
using namespace std;

int A, B;
int answer;

void dfs(long long now, int target, int depth) {
	if (now > target) {
		return;
	}
	else if (now == target) {
		answer = depth;
		return;
	}

	dfs(now * 2, target, depth + 1);
	dfs(now * 10 + 1, target, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	answer = -1;
	dfs(A, B, 1);

	cout << answer;

	return 0;
}