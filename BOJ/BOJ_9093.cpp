#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	cin.ignore();

	while (T--) {
		string str;
		stack<char> s;

		getline(cin, str);
		str += '\n';

		for (char ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else {
				s.push(ch);
			}
		}
		cout << '\n';
	}

	return 0;
}