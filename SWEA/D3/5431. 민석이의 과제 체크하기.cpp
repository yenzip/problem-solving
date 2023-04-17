#include <bits/stdc++.h>
using namespace std;

int T, N, K;
bool submit[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		memset(submit, false, sizeof(submit));
		for (int i = 0; i < K; i++) {
			int num;
			cin >> num;
			submit[num] = true;
		}

		cout << '#' << t << ' ';
		for (int i = 1; i <= N; i++) {
			if (!submit[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}