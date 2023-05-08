#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int start = 0, end = N - 1;
	int answer = 0;
	while (start < end) {
		if (A[start] + A[end] == M) {
			answer++;
			start++;
			end--;
		}
		else if (A[start] + A[end] < M) {
			start++;
		}
		else {
			end--;
		}
	}

	cout << answer;

	return 0;
}