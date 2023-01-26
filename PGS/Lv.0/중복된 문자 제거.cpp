#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string answer = "";

	for (auto c : my_string) {
		if (answer.find(c) == string::npos) {
			answer += c;
		}
	}

	return answer;
}