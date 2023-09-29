#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<bool> isPrime(1001, true);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	isPrime[0] = false;
	isPrime[1] = false;

	int answer = 0;
	int cnt = 0;
	bool isFind = false;

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!isPrime[j]) {
				continue;
			}
			isPrime[j] = false;
			cnt++;
			if (cnt == K) {
				answer = j;
				isFind = true;
				break;
			}
		}
		if (isFind) {
			break;
		}
	}

	cout << answer;

	return 0;
}