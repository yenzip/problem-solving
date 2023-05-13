#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;

	long long result = gcd(A, B);
	for (long long i = 0; i < result; i++) {
		cout << 1;
	}

	return 0;
}