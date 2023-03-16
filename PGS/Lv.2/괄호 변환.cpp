#include <string>
#include <vector>

using namespace std;

string answer = "";

int balance(string s) {
	int open = 0, close = 0;
	for (int i = 0; i < s.size(); i++) {
		if (open != 0 && open == close) {
			return i;
		}
		if (s[i] == '(') {
			open++;
		}
		else {
			close++;
		}
	}
	if (open == close) {
		return s.size();
	}
}

bool isCorrect(string s) {
	int size = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			size++;
		}
		else {
			if (size == 0) {
				return false;
			}
			else {
				size--;
			}
		}
	}

	return size ? false : true;
}

string solution(string p) {

	if (p.empty()) {	// 1단계
		return answer;
	}

	int idx = balance(p);	// 2단계
	string u = "", v = "";
	u = p.substr(0, idx);
	v = p.substr(idx);

	if (isCorrect(u)) {	// 3단계
		answer = u + solution(v);
	}
	else {	// 4단계
		answer = "(" + solution(v) + ")";
		string tmp = "";
		for (int i = 1; i < u.size() - 1; i++) {
			u[i] == '(' ? tmp += ')' : tmp += '(';
		}
		answer += tmp;
	}

	return answer;
}