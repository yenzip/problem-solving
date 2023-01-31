#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string my_string) {
	string answer = "";
	
	for (char c : my_string) {
		answer += tolower(c);
	}

	sort(answer.begin(), answer.end());

	return answer;
}