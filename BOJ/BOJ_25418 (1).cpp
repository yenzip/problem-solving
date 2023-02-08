/* »óÇâ½Ä */
#include <bits/stdc++.h>

using namespace std;

int d[1000000 + 1];

int main() {
	int A, K;
	cin >> A >> K;

	for (int i = A + 1; i <= K; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && i / 2 >= A) {
			d[i] = d[i / 2] + 1;
		}
	}

	cout << d[K];

	return 0;
}