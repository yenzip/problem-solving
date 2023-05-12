#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		pq.push(-card);
	}

	int answer = 0;
	while (pq.size() > 1) {
		int c1 = -pq.top();
		pq.pop();
		int c2 = -pq.top();
		pq.pop();
		answer += c1 + c2;
		pq.push(-(c1 + c2));
	}

	cout << answer;

	return 0;
}