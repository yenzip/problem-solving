#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";

	for (char c : s) {
		if (count(s.begin(), s.end(), c) == 1) {
			answer += c;
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}