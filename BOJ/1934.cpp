#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		cout << A * B / gcd(A, B) << "\n";
	}

	return 0;
}