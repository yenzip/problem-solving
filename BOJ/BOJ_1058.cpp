#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool isVisited[50 + 1];
int cnt = 0;	// 2 - 친구의 수
int answer = 0;	// 가장 유명한 사람의 2 - 친구의 수

void dfs(int cur, int depth) {
	if (!isVisited[cur]) {
		isVisited[cur] = true;
		cnt++;
	}

	if (depth == 2) {	// 깊이가 2이면 종료
		return;
	}

	for (int next : adj[cur]) {
		dfs(next, depth + 1);
	}
}

int main() {
	int N;

	cin >> N;

	adj.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char isFriend;
			cin >> isFriend;
			if (isFriend == 'Y') {
				adj[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(isVisited, false, sizeof(isVisited));
		dfs(i, 0);
		answer = max(answer, cnt - 1);
	}

	cout << answer;

	return 0;
}