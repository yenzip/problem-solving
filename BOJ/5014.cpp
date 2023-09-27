#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
int dx[2] = { 0, 0 };

bool isOut(int x) {
	return (x <= 0 || x > F);
}

void bfs() {
	queue<pair<int, int>> q;

	visited[S] = true;
	q.push({ S, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == G) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int next = now + dx[i];

			if (!isOut(next) && !visited[next]) {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}

	cout << "use the stairs";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	
	dx[0] = U;
	dx[1] = -D;

	bfs();

	return 0;
}