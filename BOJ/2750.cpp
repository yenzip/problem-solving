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

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << A[i] << '\n';
	}

	return 0;
}