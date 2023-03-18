#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define INF 2e9

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	// cost, road
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;

			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
 		}
	}
}


int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	graph.resize(N + 1);
	for (int i = 0; i < road.size(); i++) {
		graph[road[i][0]].push_back({ road[i][1], road[i][2] });
		graph[road[i][1]].push_back({ road[i][0], road[i][2] });
	}

	dist.resize(N + 1, INF);
	dijkstra(1);

	for (int i = 2; i <= N; i++) {
		if (dist[i] <= K) {
			answer++;
		}
	}

	return answer;
}