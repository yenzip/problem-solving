#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;	// adj: ���� ����Ʈ
bool isVisited[100 + 1];	// isVisited: �湮 ����

int dfs(int cur) {
	isVisited[cur] = true;
	int virus = 1;

	for (int next : adj[cur]) {
		if (!isVisited[next]) {
			virus += dfs(next);
		}
	}

	return virus;
}

int main() {
	int v, e;	// v: ����(��ǻ���� ��), e: ����

	cin >> v >> e;

	adj.resize(v + 1);
	memset(isVisited, false, sizeof(isVisited));

	for (int i = 0; i < e; i++) {	// �׷��� ����
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	cout << dfs(1) - 1;	// 1�� ����

	return 0;

}