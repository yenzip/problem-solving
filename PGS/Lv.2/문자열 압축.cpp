#include <bits/stdc++.h>
using namespace std;

int check(string s, int cut) {
	stack<pair<string, int>> st;
	st.push({ s.substr(0, cut), 1 });

	for (int i = cut; i < s.size(); i += cut) {
		string tmp = s.substr(i, cut);
		if (st.top().first == tmp) {
			st.top().second++;
		}
		else {
			st.push({ tmp, 1 });
		}
	}

	string result;
	while (!st.empty()) {
		if (st.top().second == 1) {
			result += st.top().first;
		}
		else {
			result += to_string(st.top().second) + st.top().first;
		}
		st.pop();
	}

	return result.size();
}

int solution(string s) {
	int answer = s.size();

	for (int i = 1; i < s.size(); i++) {
		answer = min(answer, check(s, i));
	}
	return answer;
}