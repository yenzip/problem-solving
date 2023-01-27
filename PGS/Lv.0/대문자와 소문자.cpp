#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string my_string) {
	string answer = "";

	for (char c : my_string) {
		if (isupper(c)) {
			answer += tolower(c);
		}
		else {
			answer += toupper(c);
		}
	}

	return answer;
}