#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long A[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	long long answer = INT_MAX;
	int start = 0;
	int end = 0;

	while (end <= N) {
		if (A[end] - A[start] >= M) {
			answer = min(answer, A[end] - A[start]);
			start++;
		}
		else {
			end++;
		}
	}

	cout << answer;

	return 0;
}