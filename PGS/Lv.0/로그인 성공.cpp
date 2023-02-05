#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
	string answer = "";
	bool isID = false;
	bool isPW = false;

	for (auto user : db) {
		if (user[0] == id_pw[0]) {	// ID °Ë»ç
			isID = true;
			if (user[1] == id_pw[1]) {
				isPW = true;
			}
		}
	}

	if (isID && isPW) {
		answer += "login";
	}
	else if (isID && !isPW) {
		answer += "wrong pw";
	}
	else {
		answer += "fail";
	}

	return answer;
}