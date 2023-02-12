#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	for (int i = 1; i <= n; i++) {
		i % 2 == 1 ? answer += "¼ö" : answer += "¹Ú";
	}
	return answer;
}