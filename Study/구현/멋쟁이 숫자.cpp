#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = -1;

	cin >> s;

	for (int i = 0; i <= s.size() - 3; i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
			answer = max(answer, stoi(s.substr(i, 3)));
		}
	}

	cout << answer;

	return 0;
}