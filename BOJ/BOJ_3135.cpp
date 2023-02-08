#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B, N;
	cin >> A >> B >> N;

	priority_queue<int> pq;
	pq.push(-abs(A - B));

	while (N--) {
		int bookmark;
		cin >> bookmark;
		pq.push(-(1 + abs(bookmark - B)));
	}

	cout << -pq.top();

	return 0;
}