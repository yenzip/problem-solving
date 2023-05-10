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

	for (int i = 1; i < N; i++) {
		int j, tmp = A[i];
		for (j = i - 1; j >= 0; j--) {
			if (tmp < A[j]) A[j + 1] = A[j];
			else break;
		}
		A[j + 1] = tmp;
	}

	int answer = 0;
	vector<int> S(N);
	S[0] = A[0];
	answer += A[0];
	for (int i = 1; i < N; i++) {
		S[i] = S[i - 1] + A[i];
		answer += S[i];
	}

	cout << answer;

	return 0;
}