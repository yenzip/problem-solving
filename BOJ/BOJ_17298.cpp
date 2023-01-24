#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> NGE(N, -1);
	stack<int> s;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		while (!s.empty() && A[s.top()] < A[i]) {
			NGE[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}

	for (int n : NGE) {
		cout << n << ' ';
	}

	return 0;
}