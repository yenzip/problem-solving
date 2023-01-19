#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	stack<int> s;
	string ans;

	cin >> n;

	for (int i = 0, num = 1; i < n; i++) {
		int m;
		
		cin >> m;

		while (num <= m) {
			s.push(num++);
			ans += '+';
		}

		if (s.top() == m) {
			s.pop();
			ans += '-';
		}
	}

	if (s.empty()) {
		for (char a : ans) {
			cout << a << '\n';
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}