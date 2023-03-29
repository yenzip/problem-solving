#include <bits/stdc++.h>
#define N 5
using namespace std;

int countWays1(int n) {	// 1. 재귀 호출
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return countWays1(n - 1) + countWays1(n - 2);
}

int dp[N + 1];
int countWays2(int n) {	// 2. 다이내믹 프로그래밍
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int  main() {
	
	int result1 = countWays1(N);	// 방법 1.) 재귀 호출
	cout << result1 << '\n';

	int result2 = countWays2(N);	// 방법 2.) 다이내믹 프로그래밍
	cout << result2 << '\n';

}