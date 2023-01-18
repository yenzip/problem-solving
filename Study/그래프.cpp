#include <bits/stdc++.h>

using namespace std;

int main() {
	int v, e;	// v: ����, e: ����
	vector<vector<int>> adj;	// adj: ���� ����Ʈ
	
	cin >> v >> e;

	adj.resize(v + 1);	// 1���� �����ϱ� ���� (0 ~ v)

	for (int i = 0; i < e; i++) {
		int start, end;	// start: ������, end: ����
		cin >> start >> end;
		adj[start].push_back(end);
	}

	for (int i = 1; i <= v; i++) {	// �׷��� ���
		cout << "[" << i << "] : ";
		for (int v : adj[i]) {
			cout << "[" << v << "] ";
		}
		cout << '\n';
	}

	return 0;
}