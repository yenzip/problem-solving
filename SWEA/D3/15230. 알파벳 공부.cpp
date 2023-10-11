#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	string S;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> S;

		int answer = 0;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == alphabet[i]) {
				answer++;
			}
			else {
				break;
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}