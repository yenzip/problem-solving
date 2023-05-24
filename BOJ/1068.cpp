#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph;
bool visited[50];
int root;
int deleteNode;
int answer;

void dfs(int now) {
	visited[now] = true;
	int childNode = 0;

	for (auto next : graph[now]) {
		if (next != deleteNode && !visited[next]) {
			childNode++;
			dfs(next);
		}
	}

	if (childNode == 0) {
		answer++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	graph.resize(N);
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent != -1) {
			graph[parent].push_back(i);
		}
		else {
			root = i;
		}
	}

	cin >> deleteNode;

	answer = 0;
	if (root != deleteNode) {
		dfs(root);
	}

	cout << answer;

	return 0;
}