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
		dfs(s + to_string(i), depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	dfs("", 0);

	return 0;
}