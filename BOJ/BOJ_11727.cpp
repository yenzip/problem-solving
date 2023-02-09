#include <bits/stdc++.h>

using namespace std;

int d[1000 + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	d[0] = 1;
	d[1] = 1;

	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 2 * d[i - 2];
		d[i] %= 10007;
	}

	cout << d[N];

	return 0;
}