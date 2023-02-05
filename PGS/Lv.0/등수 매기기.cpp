#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
	vector<int> answer;
	vector<double> avg;

	for (auto s : score) {
		avg.push_back((s[0] + s[1]) / 2.0);
	}

	answer.resize(avg.size(), 0);

	for (int i = 0; i < avg.size(); i++) {
		for (int j = 0; j < avg.size(); j++) {
			if (i != j && avg[i] == avg[j]) {
				continue;
			}

			if (avg[i] <= avg[j]) {
				answer[i]++;
			}
		}
	}

	return answer;
}