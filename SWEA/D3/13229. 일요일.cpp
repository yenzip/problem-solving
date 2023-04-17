#include <bits/stdc++.h>
using namespace std;

int T;
string day;
map<string, int> m = { {"SUN", 0}, {"MON", 1}, {"TUE", 2}, {"WED", 3}, {"THU", 4}, {"FRI", 5}, {"SAT", 6} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> day;
		int answer = 7;
		if (day != "SUN") {
			answer -= m[day];
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}