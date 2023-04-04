#include <bits/stdc++.h>
using namespace std;

int k;
int S[13];
int ncr[13];

void dfs(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ncr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < k; i++) {
		ncr[depth] = S[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> k;

		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}

		dfs(0, 0);
		cout << '\n';
	}

	return 0;
}