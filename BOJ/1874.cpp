#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<int> stk;
	vector<char> op;
	for (int i = 0, num = 1; i < n; i++) {
		int su;
		cin >> su;

		while (num <= su) {
			stk.push(num++);
			op.push_back('+');
		}

		if (stk.top() == su) {
			stk.pop();
			op.push_back('-');
		}
	}

	if (stk.empty()) {
		for (char c : op) {
			cout << c << '\n';
		}
	}
	else cout << "NO\n";

	return 0;
}