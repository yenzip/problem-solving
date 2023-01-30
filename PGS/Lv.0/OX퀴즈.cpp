#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
	vector<string> answer;

	for (auto q : quiz) {
		stringstream ss;
		ss.str(q);
		int num = 0;
		ss >> num;

		char c = ' ';
		int tmp = 0;
		while (ss) {
			if (c == '+') {
				num += tmp;
			}
			else if (c == '-') {
				num -= tmp;
			}
			else if (c == '=') {
				if (num == tmp) {
					answer.push_back("O");
				}
				else {
					answer.push_back("X");
				}
			}
			ss >> c >> tmp;
		}
	}

	return answer;
}