#include <bits/stdc++.h>
#define N 4
using namespace std;

int cost[4][4] = {
	{0, 10, 75, 94},
	{-1, 0, 35, 50},
	{-1, -1, 0, 80},
	{-1, -1, -1, 0}
};

int minCost1(int s, int d) {	// 1. 재귀 호출
	if (s == d || s == d - 1) {
		return cost[s][d];
	}

	int minValue = cost[s][d];
	for (int i = s + 1; i < d; i++) {
		minValue = min(minValue, minCost1(s, i) + minCost1(i, d));
	}

	return minValue;
}


int memo[N][N];
int minCost2(int s, int d) {	// 2. 메모 전략 (재귀)
	if (s == d || s == d - 1) {
		return cost[s][d];
	}

	if (memo[s][d] == 0) {
		int minValue = cost[s][d];
		for (int i = s + 1; i < d; i++) {
			minValue = min(minValue, minCost2(s, i) + minCost2(i, d));
		}
		memo[s][d] = minValue;
	}

	return memo[s][d];
}

int dp[N];
int minCost3(int n) {	// 3. 다이내믹 프로그래밍 (상향식 - 비재귀)
	dp[0] = 0;
	dp[1] = cost[0][1];

	for (int i = 2; i <= n; i++) {
		dp[i] = cost[0][i];
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + cost[j][i]);
		}
	}

	return dp[n];
}


int main() {

	int result1 = minCost1(0, N - 1);	// 방법 1.) 재귀 호출
	cout << result1 << '\n';

	int result2 = minCost2(0, N - 1);	// 방법 2.) 메모 전략
	cout << result2 << '\n';

	int result3 = minCost3(N - 1);		// 방법 3.) 다이내믹 프로그래밍
	cout << result3 << '\n';

	return 0;
}