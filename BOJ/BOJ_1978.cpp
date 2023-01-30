#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}

	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	int answer = 0;

	cin >> N;

	while (N--) {
		int num;
		cin >> num;

		if (prime(num)) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}