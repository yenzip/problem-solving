#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double> &a, const pair<int, double> &b) {
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	map<int, double> m;

	for (int i = 1; i <= N; i++) {
		double notClear = count(stages.begin(), stages.end(), i);
		int challenge = count_if(stages.begin(), stages.end(), [i](int elem) { return elem >= i; });
		m[i] = notClear / challenge;
	}

	vector<pair<int, double>> v(m.begin(), m.end());	// map - value·Î Á¤·Ä
	stable_sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		answer.push_back(i.first);
	}

	return answer;
}