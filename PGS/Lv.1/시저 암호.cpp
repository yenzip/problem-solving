#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";

	for (char c : s) {
		if (isupper(c)) {
			answer += 'A' + (c - 'A' + n) % 26;
		}
		else if (islower(c)) {
			answer += 'a' + (c - 'a' + n) % 26;
		}
		else {
			answer += c;
		}
	}
	
	return answer;
}