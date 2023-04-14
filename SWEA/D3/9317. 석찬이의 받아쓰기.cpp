#include <bits/stdc++.h>
using namespace std;

int T, N;
string correct, dict;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cin >> correct >> dict;

		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (correct[i] == dict[i]) {
				answer++;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}