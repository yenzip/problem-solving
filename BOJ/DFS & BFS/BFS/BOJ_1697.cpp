#include <bits/stdc++.h>
#define MAX 100001	// 0 <= N <= 100000
using namespace std;

int N, K;
bool visited[MAX];
int mul[3] = { 1, 1, 2 };	// { -1, +1, *2 }
int add[3] = { -1, 1, 0 };

struct info {
	int x;
	int time;
};

bool isOut(int x) {
	return (x < 0 || x > MAX);
}

void bfs(int start) {
	queue<info> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		int now = q.front().x;
		int time = q.front().time;
		q.pop();

		if (now == K) {
			cout << time << '\n';
			return;
		}

		for (int i = 0; i < 3; i++) {
			int next = now * mul[i] + add[i];
			if (!isOut(next) && !visited[next]) {
				visited[next] = true;
				q.push({ next, time + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	bfs(N);

	return 0;
}