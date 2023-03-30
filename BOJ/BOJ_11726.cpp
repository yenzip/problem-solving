#include <bits/stdc++.h>
using namespace std;

int memo[1000 + 1];
int countWay1(int n) {	// 1. 메모 전략
	if (memo[n] != 0) {
		return memo[n];
	}

	if (n == 1) {
		memo[1] = 1;
	}
	else if (n == 2) {
		memo[2] = 2;
	}
	else {
		memo[n] = (countWay1(n - 1) + countWay1(n - 2)) % 10007;
	}

	return memo[n];
}

int dp[1000 + 1];
int countWay2(int n) {	// 2. 다이내믹 프로그래밍
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int result1 = countWay1(n);	// 방법 1.) 메모 전략 (재귀)
	cout << result1 << '\n';

	int result2 = countWay2(n);	// 방법 2.) 다이내믹 프로그래밍 (반복)
	cout << result2 << '\n';

}