#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int notClear(vector<int> &stages, int s) {
	int player = 0;
	for (int i = 0; i < stages.size(); i++) {
		if (s == stages[i]) {
			player++;
		}
	}
	return player;
}

int reach(vector<int> &stages, int s) {
	int player = 0;
	for (int i = 0; i < stages.size(); i++) {
		if (s <= stages[i]) {
			player++;
		}
	}
	return player;
}

bool comp(pair<double, int> &a, pair<double, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<pair<double, int>> fail;    // {실패율, 스테이지}
	for (int stage = 1; stage <= N; stage++) {
		int nc = notClear(stages, stage);
		int r = reach(stages, stage);
		double rate;
		r == 0 ? rate = 0 : rate = nc * 1.0 / r;
		fail.push_back({ rate, stage });
	}
	sort(fail.begin(), fail.end(), comp);

	for (auto s : fail) {
		answer.push_back(s.second);
	}

	return answer;
}