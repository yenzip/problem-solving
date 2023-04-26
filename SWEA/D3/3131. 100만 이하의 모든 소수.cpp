#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
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

int main() {
	for (int i = 1; i <= 1000000; i++) {
		if (check(i)) {
			cout << i << ' ';
		}
	}
	cout << '\n';

	return 0;
}