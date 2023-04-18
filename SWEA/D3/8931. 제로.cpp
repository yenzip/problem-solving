#include <bits/stdc++.h>
using namespace std;

int TC, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> K;
		stack<int> s;
		for (int i = 0; i < K; i++) {
			int num;
			cin >> num;
			if (!num) {
				s.pop();
			}
			else {
				s.push(num);
			}
		}

		int answer = 0;
		while (!s.empty()) {
			answer += s.top();
			s.pop();
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}