#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;
	istringstream ss(s);
	stack<string> st;
	string tmp;

	while (getline(ss, tmp, ' ')) {
		if (tmp == "Z") {
			st.pop();
		}
		else {
			st.push(tmp);
		}
	}

	while (!st.empty()) {
		answer += stoi(st.top());
		st.pop();
	}

	return answer;
}