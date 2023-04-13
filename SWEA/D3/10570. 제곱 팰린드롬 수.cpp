#include <bits/stdc++.h>
using namespace std;

int T, A, B;

bool check(string s) {
	for (int i = 0, j = s.size() - 1; i <= s.size() / 2; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		int answer = 0;
		for (int i = A; i <= B; i++) {
			int tmp = sqrt(i);
			if (pow(tmp, 2) == i && check(to_string(tmp)) && check(to_string(i))) {
				answer += check(to_string(i));
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}