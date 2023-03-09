#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (auto s : skill_trees) {
		int idx = 0;
		bool is_right = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == skill[idx]) {
				idx++;
			}
			else if (skill.find(s[i]) != string::npos) {
				is_right = false;
				break;
			}
		}
		if (is_right) {
			answer++;
		}
	}

	return answer;
}