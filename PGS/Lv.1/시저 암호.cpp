#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (auto i : s) {
		if (isupper(i)) {
			answer += 'A' + ((i - 'A') + n) % 26;
		}
		else if (islower(i)) {
			answer += 'a' + ((i - 'a') + n) % 26;
		}
		else {
			answer += i;
		}
	}
	return answer;
}