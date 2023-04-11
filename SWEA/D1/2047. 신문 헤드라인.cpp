#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string headline;
	cin >> headline;

	for (int i = 0; i < headline.size(); i++) {
		if (islower(headline[i])) {
			headline[i] = toupper(headline[i]);
		}
	}
	cout << headline;

	return 0;
}