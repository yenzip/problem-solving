#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
	string answer = "";

	for (auto c : new_id) {
		if (isalpha(c)) {    // 1단계
			answer += tolower(c);
		}
		else if (isdigit(c) || c == '-' || c == '_' || c == '.') {   // 2단계
			if (c == '.' && answer.back() == '.') { // 3단계
				continue;
			}
			answer += c;
		}
	}

	// 4단계
	if (answer.front() == '.') {
		answer.erase(answer.begin());
	}
	if (answer.back() == '.') {
		answer.pop_back();
	}

	// 5단계
	if (answer.empty()) {
		answer += 'a';
	}

	// 6단계
	if (answer.size() >= 16) {
		answer = answer.substr(0, 15);
		if (answer.back() == '.') {
			answer.pop_back();
		}
	}

	// 7단계
	if (answer.size() <= 2) {
		char c = answer.back();
		while (answer.size() < 3) {
			answer += c;
		}
	}

	return answer;
}