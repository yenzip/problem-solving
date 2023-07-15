#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;
vector<vector<int>> graph;
bool visited[501];
int answer;

void bfs(int sx) {
	queue<pair<int, int>> q;
	visited[sx] = true;
	q.push({ sx, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist > 0 && dist < 3) {
			answer++;
		}

		for (int next : graph[now]) {
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

	cin >> N >> M;

	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	cout << answer;

	return 0;
}