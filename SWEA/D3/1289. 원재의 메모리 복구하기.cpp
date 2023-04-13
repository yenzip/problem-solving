#include <bits/stdc++.h>
using namespace std;

int T;
string result;
string initialVal;

void setting(int idx, int num) {
	for (int i = idx; i < result.size(); i++) {
		initialVal[i] = num;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> result;
		int answer = 0;
		initialVal = string(result.size(), '0');
		for (int i = 0; i < result.size(); i++) {
			if (result[i] != initialVal[i]) {
				setting(i, result[i]);
				answer++;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
 	}

	return 0;
}