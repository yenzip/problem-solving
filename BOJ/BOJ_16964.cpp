#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
bool visited[100000 + 1];
int order[100000 + 1];
vector<int> tmp;
vector<int> dfs_order;

bool comp(int &a, int &b) {
	return order[a] < order[b];
}

void dfs(int now) {
	visited[now] = true;
	dfs_order.push_back(now);

	for (auto next : graph[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		tmp.push_back(a);
		order[a] = i;
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);
	}

	bool answer = false;
	if (tmp.front() == 1) {
		dfs(1);
		if (tmp == dfs_order) {
			answer = true;
		}
	}

	cout << answer << '\n';

	return 0;
}