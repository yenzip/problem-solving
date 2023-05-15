#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[201][201];
int route[1001];
int parent[201];

int findParent(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> route[i];
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j]) {
				unionParent(i, j);
			}
		}
	}

	string answer = "YES\n";
	int root = findParent(route[1]);
	for (int i = 2; i <= M; i++) {
		if (root != findParent(route[i])) {
			answer = "NO\n";
			break;
		}
	}

	cout << answer;

	return 0;
}