#include <bits/stdc++.h>
using namespace std;

int T, n, x;
string p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		deque<int> dq;
		char tmp;

		cin >> p >> n;

		for (int i = 0; i < n; i++) {
			cin >> tmp >> x;
			dq.push_back(x);
		}
		cin >> tmp;
		
		if (n == 0) {
			cin >> tmp;
		}


		int way = 1;	// 1(front), 0(back)
		bool isError = false;

		for (char c : p) {
			if (c == 'R') {
				way = way == 1 ? 0 : 1;
			}
			else if (c == 'D') {
				if (dq.empty()) {
					isError = true;
					break;
				}
				if (way) {	// front
					dq.pop_front();
				}
				else {	// bacl
					dq.pop_back();
				}
			}
		}

		if (isError) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (way) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i < dq.size() - 1) {
						cout << ",";
					}
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i > 0) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
	}

	return  0;
}
