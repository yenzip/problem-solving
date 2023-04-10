#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, K;
bool visited[MAX];
int parent[MAX];	// parent[next] = now;
int mul[3] = { 1, 1, 2 };
int add[3] = { -1, 1, 0 };
vector<int> path;	// 최단 시간의 경로

struct info {
	int x;
	int time;
};

bool isOut(int x) {
	return (x < 0 || x > MAX);
}

void bfs(int start) {	// 최단 시간 구하기
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
				parent[next] = now;
				q.push({ next, time + 1 });
			}
		}
	}
}

void findPath() {	// 최단 시간의 경로 구하기
	int x = K;
	while (x != N) {
		path.push_back(x);
		x = parent[x];
	}
	path.push_back(N);

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	bfs(N);	// 최단 시간 구하기
	findPath();	// 최단 시간의 경로 구하기

	return 0;
}