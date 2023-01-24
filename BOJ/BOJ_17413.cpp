#include <bits/stdc++.h>

using namespace std;

void print(stack<char> &s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	stack<char> s;
	int tag = 0;

	getline(cin, S);

	for (char c : S) {
		if (c == '<') {
			print(s);
			cout << c;
			tag = 1;
		}
		else if (c == '>') {
			cout << c;
			tag = 0;
		}
		else if (tag) {
			cout << c;
		}
		else {
			if (c == ' ') {
				print(s);
				cout << c;
			}
			else {
				s.push(c);
			}
		}
	}

	print(s);

	return 0;
}