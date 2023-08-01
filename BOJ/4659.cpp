#include <bits/stdc++.h>
using namespace std;

string PWD;

bool checkVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> PWD;

		if (PWD == "end") {
			break;
		}

		bool isVowel = false;	// 1.
		for (auto c : PWD) {
			if (checkVowel(c)) {
				isVowel = true;
				break;
			}
		}
		if (!isVowel) {
			cout << "<" << PWD << "> is not acceptable.\n";
			continue;
		}

		bool isContinuous = false;
		for (int i = 0; i < PWD.size() - 1; i++) {
			if (i < PWD.size() - 2 && checkVowel(PWD[i]) == checkVowel(PWD[i + 1]) && checkVowel(PWD[i]) == checkVowel(PWD[i + 2])) {	// 2.
				isContinuous = true;
				break;
			}
			if (PWD[i] != 'e' && PWD[i] != 'o' && PWD[i] == PWD[i + 1]) {	// 3.
				isContinuous = true;
				break;
			}
		}

		if (isContinuous) {
			cout << "<" << PWD << "> is not acceptable.\n";
		}
		else {
			cout << "<" << PWD << "> is acceptable.\n";
		}
	}

	return 0;
}