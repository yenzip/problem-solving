#include <bits/stdc++.h>
using namespace std;

int T;
string word, s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		cin >> T;
		cin >> word >> s;
		int answer = 0;
		while (s.find(word) != string::npos) {
			answer++;
			s = s.substr(s.find(word) + word.size());
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}