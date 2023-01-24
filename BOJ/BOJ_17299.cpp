#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> A(N + 1);
	vector<int> F(MAX + 1, 0);	// F: µîÀå È½¼ö
	vector<int> NGF(N + 1, -1);	
	stack<int> s;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		F[A[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		while (!s.empty() && F[A[s.top()]] < F[A[i]]) {
			NGF[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << NGF[i] << ' ';
	}

	return 0;
}