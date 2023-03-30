#include <bits/stdc++.h>
using namespace std;

int memo[1000 + 1];
int countWay1(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}

	if (n <= 1) {
		return 1;
	}
	else {
		memo[n] = countWay1(n - 1) + countWay1(n - 2) + countWay1(n - 2);
	}
	return memo[n];
}

int dp[1000 + 1];
int countWay2(int n) {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1] + dp[i - 1];
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
		
	int result1 = countWay1(n);	// 방법 1.) 메모 전략
	cout << result1 << '\n';

	int result2 = countWay2(n);	// 방법 2.) 다이내믹 프로그래밍
	cout << result2 << '\n';

}