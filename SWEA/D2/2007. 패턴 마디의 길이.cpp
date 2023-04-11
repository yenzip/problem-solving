#include <bits/stdc++.h>
using namespace std;

int T;
string pattern;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> pattern;
		string word = "";
		for (int i = 0; i < pattern.size(); i++) {
			bool check = false;
			for (int j = 0; j < word.size(); j++) {
				if (pattern[i + j] != word[j]) {
					check = false;
					break;
				}
				else {
					check = true;
				}
			}
			if (check) {
				cout << '#' << t << ' ' << word.size() << '\n';
				break;
			}
			else {
				word += pattern[i];
			}
		}
	}
}