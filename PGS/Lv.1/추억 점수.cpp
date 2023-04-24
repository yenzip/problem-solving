#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;

	map<string, int> m;
	for (int i = 0; i < name.size(); i++) {
		m[name[i]] = yearning[i];
	}

	for (auto p : photo) {
		int total = 0;
		for (int i = 0; i < p.size(); i++) {
			if (m.find(p[i]) != m.end()) {
				total += m[p[i]];
			}
		}
		answer.push_back(total);
	}

	return answer;
}