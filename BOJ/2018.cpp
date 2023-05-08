#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int start = 1, end = 1;
	int sum = 1;
	int answer = 1;	// N = N

	while (end < N) {
		if (sum == N) {
			answer++;
			end++;
			sum += end;
		}
		else if (sum < N) {
			end++;
			sum += end;
		}
		else {
			sum -= start;
			start++;
		}
	}

	cout << answer;

	return 0;
}