#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int answer = 1;	// N 본인 포함
	int start = 1;
	int end = 1;
	int sum = 0;

	while (end <= N) {
		if (sum <= N) {
			if (sum == N) {
				answer++;
			}
			sum += end++;
		}
		else {
			sum -= start++;
		}
	}

	cout << answer;

	return 0;
}