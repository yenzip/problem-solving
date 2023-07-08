#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	vector<int> cnt(2, 0);
	char target = S[0];

	cnt[target - '0']++;

	for (int i = 1; i < S.size(); i++) {
		if (target != S[i]) {
			target = S[i];
			cnt[S[i] - '0']++;
		}
	}

	cout << min(cnt[0], cnt[1]) << endl;

	return 0;
}