#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
bool visited[101];
int cnt;

void dfs(int pass, int now) {
	visited[now] = true;
	cnt++;

	for (auto next : graph[now]) {
		if (!visited[next] && next != pass) {
			dfs(pass, next);
		}
	}
}

int solution(int n, vector<vector<int>> wires) {
	int answer = n;

	graph.resize(n + 1);
	for (auto wire : wires) {
		int a = wire[0];
		int b = wire[1];
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto wire : wires) {
		int a = wire[0];
		int b = wire[1];
		cnt = 0;
		memset(visited, false, sizeof(visited));
		dfs(a, b);
		int n1 = cnt, n2 = n - cnt;
		answer = min(answer, abs(n1 - n2));
	}

	return answer;
}