#include <bits/stdc++.h>
using namespace std;

int L, C;
char alpha[15];

bool check(string s) {
	int vowel = 0, consonant = 0;
	for (auto c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}
	}
	return (vowel >= 1 && consonant >= 2);
}

void go(int start, string s, int depth) {
	if (depth == L) {
		if (check(s)) {
			cout << s << '\n';
			return;
		}
	}

	for (int i = start; i < C; i++) {
		go(i + 1, s + alpha[i], depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	} 

	sort(alpha, alpha + C);

	go(0, "", 0);

	return 0;
}