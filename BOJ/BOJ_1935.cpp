#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	string postfix;
	cin >> N >> postfix;

	vector<int> v(N);
	stack<double> s;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (char c : postfix) {
		if (c >= 'A' && c <= 'Z') {
			s.push(v[c - 'A']);
		}
		else {
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();

			if (c == '+') {
				s.push(a + b);
			}
			else if (c == '-') {
				s.push(a - b);
			}
			else if (c == '*') {
				s.push(a * b);
			}
			else if (c == '/') {
				s.push(a / b);
			}

		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();

	return 0;
}