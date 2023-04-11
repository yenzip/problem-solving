#include <bits/stdc++.h>
using namespace std;

int A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;

	char winner;
	if (A == 1) {
		winner = B == 2 ? 'B' : 'A';
	}
	else if (A == 2) {
		winner = B == 3 ? 'B' : 'A';
	}
	else {
		winner = B == 1 ? 'B' : 'A';
	}

	cout << winner;

	return 0;
}