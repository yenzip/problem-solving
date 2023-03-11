#include <string>
#include <vector>

using namespace std;

int dp[60000 + 1];

int solution(int n) {
	int answer = 0;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
	}

	return dp[n];
}