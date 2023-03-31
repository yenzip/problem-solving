#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int maxSubStringLength(string s) {	// 다이내믹 프로그래밍
	int n = s.length();
	int maxLen = 0;
	
	dp.resize(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		dp[i][i] = s[i] - '0';
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			int k = len / 2;

			dp[i][j] = dp[i][j - k] + dp[j - k + 1][j];

			if (len % 2 == 0 && dp[i][j - k] == dp[j - k + 1][j] && maxLen < len) {
				maxLen = len;
			}
		}
	}

	return maxLen;
}

int main() {
	string s;
	cin >> s;

	int result = maxSubStringLength(s);	// 다이내믹 프로그래밍 사용
	cout << result << '\n';

	return 0;
}