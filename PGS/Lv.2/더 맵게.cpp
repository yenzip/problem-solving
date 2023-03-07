#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int> pq;
	for (auto s : scoville) {
		pq.push(-s);
	}

	while (pq.size() > 1) {
		if (-pq.top() >= K) {
			break;
		}

		int scov1 = -pq.top();
		pq.pop();
		int scov2 = -pq.top();
		pq.pop();

		pq.push(-(scov1 + scov2 * 2));
		answer++;
	}

	return -pq.top() < K ? -1 : answer;
}