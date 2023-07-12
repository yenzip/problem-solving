#include <bits/stdc++.h>
using namespace std;

int N, L;
int A[5000000];
deque<pair<int, int>> dq;	// { index, value }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dq.push_back({ 0, A[0] });

	for (int i = 1; i < N; i++) {
		cout << dq.front().second << " ";

		if (!dq.empty() && dq.front().first < i - L + 1) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().second > A[i]) {
			dq.pop_back();
		}

		dq.push_back({ i, A[i] });
	}

	cout << dq.front().second;

	return 0;
}