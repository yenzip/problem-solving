#include <bits/stdc++.h>
using namespace std;

int T, N;
string S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> S;

		int i = 0, j = N / 2;

		while (j > 0 && i < N / 2 && S[i] == S[j]) {
			i++;
			j++;
		}

		string answer = "Yes";

		if (j != N) {
			answer = "No";
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}
