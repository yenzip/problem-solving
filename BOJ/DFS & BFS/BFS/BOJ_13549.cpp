#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int N, K;
bool visited[MAX + 1];

struct Info {
	int x, time;
};

bool isOut(int x) {
	return (x < 0 || x > MAX);
}

void bfs(int start) {
	deque<Info> dq;
	visited[start] = true;
	dq.push_back({ start, 0 });

	while (!dq.empty()) {
		int now = dq.front().x;
		int time = dq.front().time;
		dq.pop_front();

		if (now == K) {
			cout << time << '\n';
			return;
		}

		if (!isOut(now * 2) && !visited[now * 2]) {
			visited[now * 2] = true;
			dq.push_front({ now * 2, time });	// 0ÃÊ
		}

		if (!isOut(now - 1) && !visited[now - 1]) {
			visited[now - 1] = true;
			dq.push_back({ now - 1, time + 1 });	// 1ÃÊ
		}

		if (!isOut(now + 1) && !visited[now + 1]) {
			visited[now + 1] = true;
			dq.push_back({ now + 1, time + 1 });	// 1ÃÊ
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	bfs(N);	// 0-1 BFS

	return 0;
}