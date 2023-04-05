#include <bits/stdc++.h>
using namespace std;

int N;
int A[8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	int answer = 0;
	do {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(A[i - 1] - A[i]);
		}
		answer = max(answer, sum);
	} while (next_permutation(A, A + N));

	cout << answer << '\n';

	return 0;
}