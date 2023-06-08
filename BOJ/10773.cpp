#include <bits/stdc++.h>
using namespace std;

int K, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++) {
		cin >> x;

		if (x == 0) {
			s.pop();
		}
		else {
			s.push(x);
		}
	}

	int answer = 0;
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	cout << answer;

	return 0;
}
