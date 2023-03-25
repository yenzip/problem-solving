#include <string>
#include <vector>

using namespace std;

int balancedIdx(string p) {
	int size = 0;
	for (int i = 0; i < p.size(); i++) {
		if (size == 0) {
			return i;
		}
		p[i] == '(' ? size++ : size--;
	}
	return -1;
}

bool isCorrect(string p) {
	int size = 0;
	for (auto c : p) {
		if (c == '(') {
			size++;
		}
		else if (c == ')') {
			if (size == 0) {
				return false;
			}
			size--;
		}
	}
	return size == 0 ? true : false;
}

string solution(string p) {
	string answer = "";

	if (p.empty()) {	// 1단계
		return "";
	}

	int idx = balancedIdx(p);	// 2단계
	string u = p.substr(0, idx);
	string v = p.substr(idx);

	if (isCorrect(u)) {	// 3단계
		answer += u;
		answer += solution(v);
	}
	else {	// 4단계
		answer += '(';
		answer += solution(v);
		answer += ')';
		for (int i = 1; i < u.size() - 1; i++) {
			u[i] == '(' ? answer += ')' : answer += '(';
		}
	}

	return answer;
}