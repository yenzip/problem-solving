#include <bits/stdc++.h>
using namespace std;

int T;

int check(int n) {
	int result = 0;
	while (n) {
		result += n % 10;
		n /= 10;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int num, minVal = 1e9, maxVal = 0;
		for (int i = 0; i < 10; i++) {
			cin >> num;
			int digit = check(num);
			minVal = min(minVal, digit);
			maxVal = max(maxVal, digit);
		}
		cout << '#' << t << ' ' << maxVal << ' ' << minVal << '\n';
	}

	return 0;
}