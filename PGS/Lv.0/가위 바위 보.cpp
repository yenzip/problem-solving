#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
	string answer = "";
	
	for (char c : rsp) {
		if (c == '2') {	// 가위 -> 바위
			answer += '0';
		}
		else if (c == '0') {	// 바위 -> 보
			answer += '5';
		}
		else if (c == '5') {	// 보 -> 가위
			answer += '2';
		}
	}

	return answer;
}