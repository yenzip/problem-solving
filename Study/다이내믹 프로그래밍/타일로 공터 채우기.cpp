#include <bits/stdc++.h>
#define N 5
using namespace std;

int countWays1(int n) {	// 1. ��� ȣ��
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return countWays1(n - 1) + countWays1(n - 2);
}

int dp[N + 1];
int countWays2(int n) {	// 2. ���̳��� ���α׷���
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int  main() {
	
	int result1 = countWays1(N);	// ��� 1.) ��� ȣ��
	cout << result1 << '\n';

	int result2 = countWays2(N);	// ��� 2.) ���̳��� ���α׷���
	cout << result2 << '\n';

}