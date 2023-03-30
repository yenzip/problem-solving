#include <bits/stdc++.h>
using namespace std;


int countWay1(int n) {	// 1. 재귀 호출
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}

	return countWay1(n - 1) + countWay1(n - 2) + countWay1(n - 3);
}

int memo[11 + 1];
int countWay2(int n) {	// 2. 메모 전략
	if (memo[n] != 0) {
		return memo[n];
	}

	if (n < 0) {
		return 0;
	}
	else if (n == 0) {
		return 1;
	}
	else {
		memo[n] = countWay1(n - 1) + countWay1(n - 2) + countWay1(n - 3);
	}

	return memo[n];
}

int dp[11 + 1];
void countWay3() {	// 3. 다이내믹 프로그래밍
	dp[0] = 1;
	for (int i = 1; i <= 11; i++) {
		if (i - 1 >= 0) {
			dp[i] += dp[i - 1];
		}
		if (i - 2 >= 0) {
			dp[i] += dp[i - 2];
		}
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
	}
}

int main() {

	int T;
	cin >> T;

	countWay3();
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

}