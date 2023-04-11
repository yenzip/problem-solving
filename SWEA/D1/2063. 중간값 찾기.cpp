#include <bits/stdc++.h>
using namespace std;

int N;
int A[199];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	cout << A[N / 2] << '\n';

	return 0;
}