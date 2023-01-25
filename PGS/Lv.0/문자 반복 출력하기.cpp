#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
	string answer = "";
	for (char c : my_string) {
		answer += string(3, c);
	}
	return answer;
}