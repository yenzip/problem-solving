#include <bits/stdc++.h>

using namespace std;

int ranking(int correct) {
	switch (correct) {
	case 6: return 1;
	case 5: return 2;
	case 4: return 3;
	case 3: return 4;
	case 2: return 5;
	default: return 6;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int maxVal, minVal = 0;
	for (auto win : win_nums) {
		if (find(lottos.begin(), lottos.end(), win) != lottos.end()) {
			minVal++;
		}
	}
	maxVal = count(lottos.begin(), lottos.end(), 0) + minVal;

	answer.push_back(ranking(maxVal));
	answer.push_back(ranking(minVal));

	return answer;
}