#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
bool visited[100000 + 1];
int order[100000 + 1];
vector<int> tmp;
vector<int> bfs_order;

bool comp(int &a, int &b) {
	return order[a] < order[b];
}

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		bfs_order.push_back(now);
		q.pop();

		for (auto next : graph[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
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
		order[a] = i;	// a의 우선순위 저장
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);	// 우선순위별 정렬
	}

	bool answer = false;
	if (tmp[0] == 1) {	// 1로 시작하는 경우만
		bfs(1);
		if (tmp == bfs_order) {
			answer = true;
		}
	}
	cout << answer << '\n';

	return 0;
}