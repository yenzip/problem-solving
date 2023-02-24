#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> st;
	for (auto i : s) {
		if (!st.empty() && st.top() == i) {
			st.pop();
		}
		else {
			st.push(i);
		}
	}

	return st.empty() ? 1 : 0;
}