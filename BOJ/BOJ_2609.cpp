#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {	// 유클리드 호제법
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int A, B;
	int GCD;

	cin >> A >> B;

	GCD = gcd(A, B);
	cout << GCD << '\n';
	cout << A * B / GCD;

	return 0;
}