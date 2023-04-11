#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		int a, b;
		cin >> a >> b;
		char answer = a < b ? '<' : a > b ? '>' : '=';
		cout << "#" << i << " " << answer << '\n';
	}

	return 0;
}