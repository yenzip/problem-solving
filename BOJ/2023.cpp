#include <bits/stdc++.h>
using namespace std;

int N;

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void dfs(int number, int depth) {
	if (depth == N) {
		if (isPrime(number)) {
			cout << number << '\n';
		}
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(number * 10 + i)) {
			dfs(number * 10 + i, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}