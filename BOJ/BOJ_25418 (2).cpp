/* BFS */
#include <bits/stdc++.h>

using namespace std;

int A, K;
const int MAX = 1000000;
int visited[MAX + 1];

void bfs() {
	queue<int> q;

	q.push(A);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			return;
		}

		if (cur + 1 <= K && !visited[cur + 1]) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur * 2 <= K && !visited[cur * 2]) {
			q.push(cur * 2);
			visited[cur * 2] = visited[cur] + 1;
		}
	}
}

int main() {
	cin >> A >> K;

	bfs();

	cout << visited[K];

	return 0;
}