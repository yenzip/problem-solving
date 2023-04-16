#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int dist[20001];

void bfs(int start) {
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : graph[now]) {
			if (dist[next] == -1) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	graph.resize(n + 1);
	for (auto e : edge) {
		int a = e[0], b = e[1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	memset(dist, -1, sizeof(dist));
	bfs(1);

	int maxDist = *max_element(dist + 1, dist + n + 1);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == maxDist) {
			answer++;
		}
	}

	return answer;
}