#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
	string answer = "";

	stringstream ss(polynomial);
	string tmp;
	int coef = 0, cons = 0;
	while (ss >> tmp) {
		if (tmp == "+") {
			continue;
		}

		if (tmp.back() == 'x') {
			if (tmp.front() == 'x') {
				coef += 1;
			}
			else {
				coef += stoi(tmp.substr(0, tmp.size() - 1));
			}
		}
		else {
			cons += stoi(tmp);
		}
	}

	if (coef == 0 && cons == 0) {
		answer = "0";
	}
	else if (coef == 0) {
		answer += to_string(cons);
	}
	else {
		coef == 1 ? answer += 'x' : answer += to_string(coef) + "x";
		cons == 0 ? answer : answer += " + " + to_string(cons);
	}

	return answer;
}