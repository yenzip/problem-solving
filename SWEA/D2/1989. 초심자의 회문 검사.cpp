#include <bits/stdc++.h>
using namespace std;

int T;
string word;

bool check() {
	int size = word.size();
	for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
		if (word[i] != word[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> word;
		cout << '#' << i << ' ' << check() << '\n';
	}

	return 0;
}