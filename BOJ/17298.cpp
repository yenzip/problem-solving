#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> NGE(N, -1);
	stack<int> stk;
	for (int i = 0; i < N; i++) {
		while (!stk.empty() && A[stk.top()] < A[i]) {
			NGE[stk.top()] = A[i];
			stk.pop();
		}
		stk.push(i);
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}

	return 0;
}