#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() <<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}
