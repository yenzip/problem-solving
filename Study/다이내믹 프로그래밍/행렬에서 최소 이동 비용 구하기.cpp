#include <bits/stdc++.h>
#define M 3
#define N 4
using namespace std;

int cost[M][N] = {
	{1, 3, 5, 8},
	{4, 2, 1, 7},
	{4, 3, 2, 3}
};

int minPathCost1(int m, int n) {	// 1. 재귀 호출
	if (m == 0 && n == 0) {
		return cost[0][0];
	}
	if (m == 0) {
		return minPathCost1(0, n - 1) + cost[0][n];
	}
	if (n == 0) {
		return minPathCost1(m - 1, 0) + cost[m][0];
	}

	int x = minPathCost1(m - 1, n);
	int y = minPathCost1(m, n - 1);
	return min(x, y) + cost[m][n];
}


int memo[M][N];
int minPathCost2(int m, int n) {	// 2. 메모 전략
	if (memo[m][n] != 0) {
		return memo[m][n];
	}
	
	if (m == 0 && n == 0) {
		memo[0][0] = cost[0][0];
	}
	else if (m == 0) {
		memo[0][n] = minPathCost2(0, n - 1) + cost[0][n];
	}
	else if (n == 0) {
		memo[m][0] = minPathCost2(m - 1, 0) + cost[m][0];
	}
	else {
		int x = minPathCost1(m - 1, n);
		int y = minPathCost1(m, n - 1);
		memo[m][n] = min(x, y) + cost[m][n];
	}

	return memo[m][n];
}

int dp[M][N];
int minPathCost3() {	// 3. 다이내믹 프로그래밍
	dp[0][0] = cost[0][0];

	for (int i = 1; i < M; i++) {
		dp[i][0] = dp[i - 1][0] + cost[i][0];
	}

	for (int j = 1; j < N; j++) {
		dp[0][j] = dp[0][j - 1] + cost[0][j];
	}
	

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
		}
	}

	return dp[M - 1][N - 1];
}

#define INF 100
int d[M][N];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int dijkstra(int sx, int sy) {	// 4. 다익스트라
	memset(d, INF, sizeof(d));

	priority_queue<pair< int, pair<int, int>>> pq;
	d[sx][sy] = cost[sx][sy];
	pq.push({ -cost[sx][sy], {sx, sy} });

	while(!pq.empty()) {
		int dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (d[x][y] < dist) {
			continue;
		}

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int c = dist + cost[nx][ny];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
				continue;
			}
			else if (c < d[nx][ny]) {
				d[nx][ny] = c;
				pq.push({ -c, { nx, ny } });
			}
		}
	}

	return d[M - 1][N - 1];
}

int main() {
	
	int result1 = minPathCost1(M - 1, N - 1);	// 방법 1.) 재귀
	cout << result1 << '\n';

	int result2 = minPathCost2(M - 1, N - 1);	// 방법 2.) 메모 전략
	cout << result2 << '\n';

	int result3 = minPathCost3();				// 방법 3.) 다이내믹 프로그래밍
	cout << result3 << '\n';

	int result4 = dijkstra(0, 0);				// 방법 4.) 최단 경로 - 다익스트라
	cout << result4 << '\n';
	  
}