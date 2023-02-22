#include <bits/stdc++.h>

using namespace std;

int K, V, E;
vector<vector<int>> adj;
int visited[20000 + 1];
string answer;

void dfs(int cur) {
	for (int next : adj[cur]) {
		if (visited[next] == 0) {
			visited[next] = visited[cur] * -1;
			dfs(next);
		}
		else if(visited[next] == visited[cur]){
			answer = "NO";
		}
	}
}

int main() {
	cin >> K;

	while (K--) {
		cin >> V >> E;

		adj.resize(V + 1);
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		answer = "YES";
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i);
			}
			if (answer == "NO") {
				break;
			}
		}

		cout << answer << endl;

		adj.clear();
	}

	return 0;
}