#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {

	vector<int> dp(y + 1, y + 1);

	dp[x] = 0;
	for (int i = x; i <= y; i++) {
		if (i + n <= y) {
			dp[i + n] = min(dp[i + n], dp[i] + 1);
		}
		if (i * 2 <= y) {
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		}
		if (i * 3 <= y) {
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
		}
	}

	return dp[y] == y + 1 ? -1 : dp[y];
}