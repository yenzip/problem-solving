#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, x, y;
vector<vector<int>> graph;
bool visited[101];
int answer;

void bfs() {
	queue<pair<int, int>> q;
	visited[s] = true;
	q.push({ s, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (now == e) {
			answer = dist;
			return;
		}

		for (auto next : graph[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s >> e >> m;
	
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	answer = -1;
	bfs();

	cout << answer;

	return 0;
}