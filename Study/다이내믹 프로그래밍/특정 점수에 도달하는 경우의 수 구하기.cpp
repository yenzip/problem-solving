#include <bits/stdc++.h>
#define N 13
using namespace std;

int wayToScore1(int n) {	// 1. 재귀 호출
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	return wayToScore1(n - 3) + wayToScore1(n - 5) + wayToScore1(n - 10);
}

int dp[N + 1];
int wayToScore2(int n) {	// 2. 다이내믹 프로그래밍
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
		if (i - 5 >= 0) {
			dp[i] += dp[i - 5];
		}
		if (i - 10 >= 0) {
			dp[i] += dp[i - 10];
		}
	}
	return dp[n];
}

int main() {

	int result1 = wayToScore1(N);	// 방법 1.) 재귀 호출
	cout << result1 << '\n';
	
	int result2 = wayToScore2(N);	// 방법 2.) 다이내믹 프로그래밍
	cout << result2 << '\n';

}