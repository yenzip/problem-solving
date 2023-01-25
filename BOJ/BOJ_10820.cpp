#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;

	while (getline(cin, S)) {
		int lower = 0, upper = 0, number = 0, space = 0;

		for (char c : S) {
			if (c >= 'a' && c <= 'z') {
				lower++;
			}
			else if (c >= 'A' && c <= 'Z') {
				upper++;
			}
			else if (c >= '0' && c <= '9') {
				number++;
			}
			else if (c == ' ') {
				space++;
			}
		}

		cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
	}

	return 0;
}