#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int sum = accumulate(A, A + K, 0);
	int answer = sum;
	
	for (int i = K; i < N; i++) {
		sum += A[i];
		sum -= A[i - K];
		answer = max(answer, sum);
	}

	cout << answer;

	return 0;
}