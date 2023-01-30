#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int T;

	cin >> T;

	while (T--) {
		int A, B, GCD;
		cin >> A >> B;
		GCD = gcd(A, B);
		cout << A * B / GCD << '\n';
	}

	return 0;
}