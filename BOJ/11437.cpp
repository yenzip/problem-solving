#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;
bool visited[50001];

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	parent[start] = 0;
	depth[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : tree[now]) {
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = now;
				depth[next] = depth[now] + 1;
				q.push(next);
			}
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}

	while (depth[a] < depth[b]) {	// 2. Make the depth of two nodes equal
		b = parent[b];
	}

	while (a != b) {	// 3. Find the least common ancestor of the two nodes
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	tree.resize(N + 1);
	parent.resize(N + 1);
	depth.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs(1);	// 1. Get parent and depth

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}

	return 0;
}