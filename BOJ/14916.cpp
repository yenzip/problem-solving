#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, answer = 100000;
	int coin2 = 0, coin5 = 1;	// 2원, 5원의 개수

	cin >> n;

	while (n >= 5 * coin5) {
		if ((n - 5 * coin5) % 2 == 0) {
			coin2 = (n - 5 * coin5) / 2;
			answer = min(answer, coin5 + coin2);
		}
		coin5++;
	}

	if (answer == 100000) {
		answer = n % 2 == 0 ? n / 2 : -1;
	}

	cout << answer;

	return 0;
}