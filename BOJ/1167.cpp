#include <bits/stdc++.h>
using namespace std;

struct Node {
	int v;
	int dist;
};

int V;
vector<Node> graph[100001];
bool visited[100001];
int maxNode, maxDist;

void dfs(int now, int dist) {
	visited[now] = true;
	
	if (maxDist < dist) {
		maxDist = dist;
		maxNode = now;
	}

	for (Node next : graph[now]) {
		if (!visited[next.v]) {
			dfs(next.v, dist + next.dist);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	for (int i = 1; i <= V; i++) {
		int s, e, d;
		cin >> s >> e;
		while (e != -1) {
			cin >> d;
			graph[s].push_back({ e, d });
			cin >> e;
		}
	}

	dfs(1, 0);

	memset(visited, false, sizeof(visited));
	dfs(maxNode, 0);

	cout << maxDist;

	return 0;
}
