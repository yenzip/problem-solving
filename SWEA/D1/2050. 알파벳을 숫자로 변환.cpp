#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string alpha;
	cin >> alpha;

	for (int i = 0; i < alpha.size(); i++) {
		if (isupper(alpha[i])) {
			cout << alpha[i] - 'A' + 1 << ' ';
		}
		else {
			cout << alpha[i] - 'a' + 1 << ' ';
		}
	}
	
	return 0;
}