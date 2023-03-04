#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<int> distribution;
	for (int i = 0; i < progresses.size(); i++) {
		int day = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];
			day++;
		}
		if (!distribution.empty() && distribution.back() > day) {
			distribution.push_back(distribution.back());
		}
		else {
			distribution.push_back(day);
		}
	}

	int i = 0;
	while (i < distribution.size()) {
		int cnt = count(distribution.begin(), distribution.end(), distribution[i]);
		answer.push_back(cnt);
		i += cnt;
	}

	return answer;
}