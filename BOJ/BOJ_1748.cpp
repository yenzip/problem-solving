#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 0;
	int i = 1;
	int len = 1;
	for ( ; i <= N / 10; i *= 10, len++) {
		answer += (i * 10 - i) * len;
	}
	answer += (N - i + 1) * len;

	cout << answer << '\n';

	return 0;
}