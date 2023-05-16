#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> indegree;
vector<int> hour;
vector<int> answer;

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : graph[now]) {
			answer[next] = max(answer[next], answer[now] + hour[now]);
			indegree[next]--;
			if (!indegree[next]) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	graph.resize(N + 1);
	indegree.resize(N + 1, 0);
	hour.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> hour[i];

		int node;
		cin >> node;
		while (node != -1) {
			graph[node].push_back(i);
			indegree[i]++;
			cin >> node;
		}
	}

	answer.resize(N + 1, 0);
	topology_sort();

	for (int i = 1; i <= N; i++) {
		cout << answer[i] + hour[i] << "\n";
	}

	return 0;
}