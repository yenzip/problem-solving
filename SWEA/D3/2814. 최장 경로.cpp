#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[11];
bool visited[11];
int answer;

void dfs(int now, int sum) {
	visited[now] = true;
	answer = max(answer, sum);

	for (auto next : graph[now]) {
		if (!visited[next]) {
			dfs(next, sum + 1);
		}
	}

	visited[now] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		answer = 0;
		for (int i = 1; i <= N; i++) {
			dfs(i, 1);
		}

		cout << "#" << tc << " " << answer << "\n";

		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
	}

	return 0;
}