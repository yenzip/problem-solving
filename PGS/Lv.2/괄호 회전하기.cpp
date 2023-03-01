#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		stack<char> st;
		bool isVPS = true;
		for (auto c : s) {
			if (c == '(' || c == '{' || c == '[') {
				st.push(c);
			}
			else if (c == ')' || c == '}' || c == ']') {
				if (st.empty()) {
					isVPS = false;
					break;
				}
				else if ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')) {
					st.pop();
				}
			}
		}

		st.empty() && isVPS ? answer++ : answer;

		s.push_back(s.front());
		s.erase(s.begin());
	}

	return answer;
}