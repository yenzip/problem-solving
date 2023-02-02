#include <bits/stdc++.h>

using namespace std;

int N, K;
const int MAX = 100000;
int level[MAX + 1];
int dMul[3] = {2, 1, 1};
int dAdd[3] = { 0, -1, 1 };

int isOut(int point) {
	return (point < 0 || point > MAX);
}

void bfs() {
	queue<int> q;

	level[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			return;
		}

		for (int i = 0; i < 3; i++) {
			int next = cur * dMul[i] + dAdd[i];

			if (!isOut(next) && level[next] == -1) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	memset(level, -1, sizeof(level));

	bfs();

	cout << level[K];

	return 0;
}