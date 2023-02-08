/* BFS */
#include <bits/stdc++.h>

using namespace std;

int adj[1000 + 1];
bool visited[1000 + 1];
int cnt;

void bfs(int start) {
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cnt++;

		while (!visited[adj[cur]]) {
			q.push(adj[cur]);
			visited[adj[cur]] = true;
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int answer;
		cin >> answer;
		adj[i] = answer;
	}

	int max = 0, minIdx;
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));

		bfs(i);

		if (max < cnt) {
			max = cnt;
			minIdx = i;
		}
	}

	cout << minIdx;

	return 0;
}
