#include <string>
#include <vector>
#include <regex>
#include <map>
#include <sstream>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

vector<int> solution(string s) {
	vector<int> answer;

	s = regex_replace(s, regex("[{]+"), "");
	s = regex_replace(s, regex("[}]+"), "");
	s = regex_replace(s, regex(","), " ");

	map<int, int> m;
	stringstream ss(s);
	int num;
	while (ss >> num) {
		m[num]++;
	}

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), comp);

	for (auto i : v) {
		answer.push_back(i.first);
	}

	return answer;
}