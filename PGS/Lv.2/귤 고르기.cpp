#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	map<int, int> m;
	for (auto i : tangerine) {
		m[i]++;
	}

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), comp);

	for (auto i : v) {
		if (k <= 0) {
			break;
		}

		k -= i.second;
		answer++;
	}

	return answer;
}