#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
	int answer = 2;

	for (auto d : dic) {
		int exist = 0;
		for (auto s : spell) {
			if (d.find(s) != string::npos) {
				exist++;
			}
		}
		if (exist == spell.size()) {
			return 1;
		}
	}

	return answer;
}