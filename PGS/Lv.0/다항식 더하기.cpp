#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
	string answer = "";
	istringstream ss(polynomial);
	string tmp = "";
	int coef = 0;
	int cons = 0;

	while (getline(ss, tmp, ' ')) {
		int index = tmp.find('x');

		if (index != string::npos) {
			if (index == 0) {
				coef += 1;
			}
			else {
				tmp = tmp.substr(0, index);
				coef += stoi(tmp);
			}
		}
		else if (isdigit(tmp[0])) {
			cons += stoi(tmp);
		}
	}

	if (coef == 0 && cons == 0) {
		answer += "0";
	}
	else {
		if (coef != 0) {
			if (coef == 1) {
				answer += "x";
			}
			else {
				answer += to_string(coef) + "x";
			}
		}

		if (cons != 0) {
			if (coef != 0) {
				answer += " + ";
			}
			answer += to_string(cons);
		}
	}

	return answer;
}