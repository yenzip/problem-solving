#include <bits/stdc++.h>
using namespace std;

int memo[1000000 + 1];
int countWay1(int n) {	// 1. 메모 전략
	if (memo[n] != 0) {
		return memo[n];
	}

	if (n == 1) {	// 종료조건
		return 0;
	}
	if (n - 1 >= 1) {
		memo[n] = countWay1(n - 1) + 1;
	}
	if (n % 2 == 0) {
		int tmp = countWay1(n / 2) + 1;
		if (memo[n] > tmp) {
			memo[n] = tmp;
		}
	}
	if (n % 3 == 0) {
		int tmp = countWay1(n / 3) + 1;
		if (memo[n] > tmp) {
			memo[n] = tmp;
		}
	}

	return memo[n];
}

int dp[1000000 + 1];	// 2. 다이내믹 프로그래밍
int countWay2(int n) {
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i - 1 >= 1) {
			dp[i] = dp[i - 1] + 1;
		}
		if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
			dp[i] = dp[i / 2] + 1;
		}
		if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
			dp[i] = dp[i / 3] + 1;
		}
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int result1 = countWay1(N);	// 방법 1.) 메모 전략 (재귀)
	cout << result1 << endl;

	int result2 = countWay2(N);	// 방법 2.) 다이내믹 프로그래밍 (반복)
	cout << result2 << '\n';
	
}