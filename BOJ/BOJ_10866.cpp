#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	deque<int> d;

	cin >> N;

	while (N--) {
		string cmd;

		cin >> cmd;

		if (cmd == "push_front") {
			int X;
			cin >> X;
			d.push_front(X);
		}
		else if (cmd == "push_back") {
			int X;
			cin >> X;
			d.push_back(X);
		}
		else if (cmd == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << d.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << d.empty() << '\n';
		}
		else if (cmd == "front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
			}
		}
	}

	return 0;
}