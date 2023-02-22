#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;
bool visited[2000];
int answer = 0;

void dfs(int cur, int depth) {
	if (depth == 4) {
		answer = 1;
		return;
	}

	for (int next : adj[cur]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, depth + 1);
			visited[next] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	adj.resize(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 0);
		visited[i] = false;

		if (answer == 1) {
			break;
		}
	}

	cout << answer;

	return 0;
}