#include <bits/stdc++.h>
using namespace std;

struct compare{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				x = pq.top();
				pq.pop();
			}
			cout << x << '\n';
		}
		else pq.push(x);
	}

	return 0;
}