#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	vector<pair<int, int>> v;
	for (int i = 0; i < priorities.size(); i++) {
		v.push_back({ priorities[i], i });
	}

	int seq = 1;
	while (!v.empty()) {
		int cur = v.front().first;
		int idx = v.front().second;
		v.erase(v.begin());

		bool isEssential = true;
		for (auto i : v) {
			if (i.first > cur) {
				isEssential = false;
				break;
			}
		}

		if (!isEssential) {
			v.push_back({ cur, idx });
		}
		else {
			if (idx == location) {
				answer = seq;
				break;
			}
			seq++;
		}
	}

	return answer;
}