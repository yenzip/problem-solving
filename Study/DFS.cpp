#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;	// adj: ���� ����Ʈ
bool isVisited[1000 + 1];		// isVisited: �湮 ����

void dfs(int cur) {	// cur : ���� ����
	if (isVisited[cur]) {	// ���� ��� �湮 �� return
		return;
	}

	isVisited[cur] = true;	// ���� ���� �湮
	cout << "[" << cur << "] ";	// ���� ���
		
	for (int next : adj[cur]) {	// �ֱ� �湮�� ������ ������ ���� �湮
		dfs(next);
	}
}

int main() {
	int v, e;	// v : ����, e : ����

	cin >> v >> e;

	adj.resize(v + 1);	// 0 ~ v
	memset(isVisited, false, sizeof(isVisited));	// 0 ~ v

	for (int i = 0; i < e; i++) {	// �׷��� ����
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
	}

	dfs(1);	// ���̿켱Ž��

	return 0;
}