#include <bits/stdc++.h>
using namespace std;

#define INF 20001
int N, M;
vector<vector<int>> graph;
vector<int> d;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) {
			continue;
		}

		for (auto next : graph[now]) {
			int cost = dist + 1;
			if (cost < d[next]) {
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	cout << "�׷��� �ϼ�" <<endl;

	d.resize(N + 1, INF);
	dijkstra(1);

	int maxDistance = *max_element(d.begin() + 1, d.begin() + N + 1);	// �ִ� �Ÿ�
	int shed = find(d.begin() + 1, d.begin() + N + 1, maxDistance) - d.begin();	// �갣 ��ȣ
	int cnt = count(d.begin() + 1, d.begin() + N + 1, maxDistance);	// ���� �Ÿ� ���� �갣 ����
	cout << shed << ' ' << maxDistance << ' ' << cnt << '\n';

	return 0;
}