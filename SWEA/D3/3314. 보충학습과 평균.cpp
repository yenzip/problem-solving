#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 1; t <= T; t++) {
		int answer = 0;
		for (int i = 0; i < 5; i++) {
			int score;
			cin >> score;
			answer += score < 40 ? 40 : score;
		}
		cout << '#' << t << ' ' << answer / 5 << '\n';
	}

	return 0;
}