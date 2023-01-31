#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
long long A[MAX];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long S;

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long D = abs(S - A[0]);
	for (int i = 1; i < N; i++) {
		D = gcd(D, abs(S - A[i]));
	}
	cout << D;

	return 0;
}