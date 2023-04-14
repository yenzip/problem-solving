#include <bits/stdc++.h>
using namespace std;

int T;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> T) {
		for (int i = 0; i < 8; i++) {
			int num;
			cin >> num;
			dq.push_back(num);
		}

		bool exit = false;
		while (1) {
			if (exit) {
				break;
			}
			for (int i = 0; i < 5; i++) {
				int cur = dq.front() - (i % 5 + 1);
				if (cur <= 0) {
					cur = 0;
				}
				dq.pop_front();
				dq.push_back(cur);
				if (cur == 0) {
					exit = true;
					break;
				}
			}
		}
		cout << '#' << T << ' ';
		while (!dq.empty()) {
			cout << dq.front() << ' ';
			dq.pop_front();
		}
		cout << '\n';
	}

	return 0;
}