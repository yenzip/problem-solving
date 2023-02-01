#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;	// adj: ���� ����Ʈ
bool visited[1000 + 1];		// visited: �湮 ����

void dfs(int cur) {
	visited[cur] = true;	// ���� ���� �湮	
	cout << cur << '\n';	// ���� ���

	for (int next : adj[cur]) {	// �ֱ� �湮�� ������ ������ ���� �湮
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	int v, e;	// v : ����, e : ����
	cin >> v >> e;

	adj.resize(v + 1);	// 0 ~ v
	memset(visited, false, sizeof(visited));	// 0 ~ v

	for (int i = 0; i < e; i++) {	// �׷��� ����
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	dfs(1);	// ���̿켱Ž��

	return 0;
}