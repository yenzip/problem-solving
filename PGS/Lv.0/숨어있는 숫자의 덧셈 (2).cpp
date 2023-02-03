#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
	int answer = 0;

	string num = "";
	for (char c : my_string) {
		if (isdigit(c)) {
			num.push_back(c);
		}
		else {
			if (!num.empty()) {
				answer += stoi(num);
				num = "";
			}
		}
	}

	if (!num.empty()) {
		answer += stoi(num);
	}

	return answer;
}