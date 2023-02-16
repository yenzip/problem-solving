#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	sort(strings.begin(), strings.end());

	multimap<char, string> mm;

	for (auto s : strings) {
		mm.insert(make_pair(s[n], s));
	}

	for (auto i : mm) {
		answer.push_back(i.second);
	}

	return answer;
}