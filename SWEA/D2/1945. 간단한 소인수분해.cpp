#include <bits/stdc++.h>
using namespace std;

int T, N;
int factor[5] = { 2, 3, 5, 7, 11 };

int factorization(int num) {
	int exp = 0;
	while (N % num == 0) {
		N /= num;
		exp++;
	}
	return exp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << '#' << i << ' ';
		for (int j = 0; j < 5; j++) {
			cout << factorization(factor[j]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}