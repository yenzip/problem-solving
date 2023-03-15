#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
	queue<int> q;
	q.push(x);
	vector<int> dist(y + 1, 0);
	dist[x] = 1;

	while (!q.empty()) {
		int cur = q.front();
		int d = dist[cur];
		q.pop();

		if (cur == y) {
			break;
		}

		if (cur + n <= y && dist[cur + n] == 0) {
			q.push(cur + n);
			dist[cur + n] = d + 1;
		}
		if (cur * 2 <= y && dist[cur * 2] == 0) {
			q.push(cur * 2);
			dist[cur * 2] = d + 1;
		}
		if (cur * 3 <= y && dist[cur * 3] == 0) {
			q.push(cur * 3);
			dist[cur * 3] = d + 1;
		}
	}
	
	return dist[y] ? dist[y] - 1 : -1;
}