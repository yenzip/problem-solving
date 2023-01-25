#include <bits/stdc++.h>

using namespace std;

int priority(char op) {
	if (op == '(') {
		return 0;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}

}

int main() {
	string exp;
	string postfix;

	cin >> exp;

	stack<char> s;
	int isBracket = 0;

	for (char c : exp) {
		if (c >= 'A' && c <= 'Z') {
			postfix += c;
		}
		else if (c == '(') {
			s.push(c);
		}
		else if (c == ')') {
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();	// '('
		}
		else {
			while (!s.empty() && priority(s.top()) >= priority(c)) {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		}
	}

	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	cout << postfix;

	return 0;
}