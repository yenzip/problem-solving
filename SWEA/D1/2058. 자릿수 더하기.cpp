#include <bits/stdc++.h>
using namespace std;

int N;
int answer;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N) {
		answer += N % 10;
		N /= 10;
	}

	cout << answer << '\n';

	return 0;
}