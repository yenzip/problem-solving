#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ranking(int n) {
	switch (n) {
	case 0: case 1:
		return 6;
	case 2:
		return 5;
	case 3:
		return 4;
	case 4:
		return 3;
	case 5:
		return 2;
	case 6:
		return 1;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int match = 0;
	for (auto i : win_nums) {
		if (find(lottos.begin(), lottos.end(), i) != lottos.end()) {
			match++;
		}
	}

	int zero = count(lottos.begin(), lottos.end(), 0);
	answer.push_back(ranking(match + zero));
	answer.push_back(ranking(match));
	
	return answer;
}