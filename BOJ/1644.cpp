#include <bits/stdc++.h>
using namespace std;

int N;
vector<bool> check;
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	check = vector<bool>(N + 1, true);	// 에라토스테네스의 체

	check[1] = false;

	for (int i = 2; i <= N; i++) {
		if (check[i]) {
			for (int j = i * 2; j <= N; j += i) {
				check[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (check[i]) {
			prime.push_back(i);
		}
	}

	int answer = check[N];	// 투포인터
	int start = 0;
	int end = 0;
	int sum = 0;

	while (end < prime.size()) {
		if (sum <= N) {
			if (sum == N) {
				answer++;
			}
			sum += prime[end++];
		}
		else {
			sum -= prime[start++];
		}
	}

	cout << answer;

	return 0;
}