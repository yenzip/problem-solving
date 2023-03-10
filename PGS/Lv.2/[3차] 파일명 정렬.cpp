#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, pair<string, int>> &a, const pair<int, pair<string, int>> &b) {
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	vector<pair<int, pair<string, int>>> v;
	for (int i = 0; i < files.size(); i++) {
		string head, number;
		for (auto& j : files[i]) {
			if (isdigit(j)) {
				number += j;
			}
			else {
				if (!number.empty()) {
					break;
				}
				head += tolower(j);
			}
		}
		if (number.empty()) {
			number = "0";
		}
		v.push_back({ i, {head, stoi(number)} });
	}

	stable_sort(v.begin(), v.end(), comp);

	for (auto i : v) {
		answer.push_back(files[i.first]);
	}

	return answer;
}