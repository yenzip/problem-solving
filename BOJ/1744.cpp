#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> minus_pq, plus_pq;
	int one = 0, zero = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < 0) {
			minus_pq.push(-num);
		}
		else if (num == 0) {
			zero++;
		}
		else if (num == 1) {
			one++;
		}
		else {
			plus_pq.push(num);
		}
	}

	int answer = one;

	while (minus_pq.size() > 1) {
		int n1 = -minus_pq.top();
		minus_pq.pop();
		int n2 = -minus_pq.top();
		minus_pq.pop();
		answer += n1 * n2;
	}
	if (!minus_pq.empty()) {
		if (zero == 0) {
			answer += -minus_pq.top();
		}
	}

	while (plus_pq.size() > 1) {
		int n1 = plus_pq.top();
		plus_pq.pop();
		int n2 = plus_pq.top();
		plus_pq.pop();
		answer += n1 * n2;
	}
	if (!plus_pq.empty()) {
		answer += plus_pq.top();
	}

	cout << answer;

	return 0;
}