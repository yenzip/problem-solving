#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[200000];
int cnt[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int answer = 0;
	int start = 0;
	int end = 0;

	while (end < N) {
		cnt[A[end]]++;

		while (start <= end && cnt[A[end]] > K) {
			cnt[A[start]]--;
			start++;
		}

		answer = max(answer, end - start + 1);

		end++;
	}

	cout << answer;

	return 0;
}