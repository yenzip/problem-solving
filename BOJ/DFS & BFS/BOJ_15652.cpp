#include <bits/stdc++.h>
using namespace std;

int N, M;

void dfs(string s, int depth) {
	if (depth == M) {
		for (auto c : s) {
			cout << c << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (s.back() - '0' <= i) {
			dfs(s + to_string(i), depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dfs(to_string(i), 1);
	}

	return 0;
}