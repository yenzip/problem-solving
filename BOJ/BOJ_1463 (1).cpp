/* ÇÏÇâ½Ä */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int d[MAX + 1];

int go(int n) {
	if (n == 1) {	// 1 -> 1
		return 0;
	}
	if (d[n] > 0) {	// memorization
		return d[n];
	}

	d[n] = go(n-1) + 1;	// N - 1 
	if (n % 2 == 0) {	// N / 2
		int tmp = go(n / 2) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	if (n % 3 == 0) {	// N / 3
		int tmp = go(n / 3) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}

	return d[n];
}

int main() {
	int N;
	cin >> N;

	cout << go(N);

	return 0;
}