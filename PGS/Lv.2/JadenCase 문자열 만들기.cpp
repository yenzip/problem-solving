#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	for (int i = 0; i < s.size(); i++) {
		if ((answer.empty() || s[i - 1] == ' ') && isalpha(s[i])) {
			s[i] = toupper(s[i]);
		}
		else if (isalpha(s[i])) {
			s[i] = tolower(s[i]);
		}
		answer += s[i];
	}

	return answer;
}