#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;

	getline(cin, S);

	for (char c : S) {
		if (c >= 'A' && c <= 'Z') {
			cout << (char)((c - 'A' + 13) % 26 + 'A');
		}
		else if (c >= 'a' && c <= 'z') {
			cout << (char)((c - 'a' + 13) % 26 + 'a');
		}
		else {
			cout << c;
		}
	}

	return 0;
}