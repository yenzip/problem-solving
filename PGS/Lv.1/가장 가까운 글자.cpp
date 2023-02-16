#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	answer.push_back(-1);
	for (int i = 1; i < s.size(); i++) {
		if (s.rfind(s[i], i - 1) == string::npos) {
			answer.push_back(-1);
		}
		else {
			answer.push_back(i - (s.rfind(s[i], i - 1)));
		}
	}

	return answer;
}