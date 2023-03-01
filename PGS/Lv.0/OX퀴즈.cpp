#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
	vector<string> answer;

	for (auto s : quiz) {
		stringstream ss(s);
		int a, b, res;
		char op, eq;
		ss >> a >> op >> b >> eq >> res;

		if (op == '+') {
			a + b == res ? answer.push_back("O") : answer.push_back("X");
		}
		else {
			a - b == res ? answer.push_back("O") : answer.push_back("X");
		}
	}

	return answer;
}