#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;	

	map<string, vector<string>> m;
	for (auto c : clothes) {
		m[c[1]].push_back(c[0]);
	}

	for (auto i : m) {
		answer *= (i.second.size() + 1);
	}
	answer -= 1;

	return answer;
}