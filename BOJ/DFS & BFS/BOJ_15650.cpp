#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[8 + 1];

void dfs(string s, int depth) {
	if (depth == M) {
		for (auto c : s) {
			cout << c << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && s.back() - '0' < i) {
			visited[i] = true;
			dfs(s + to_string(i), depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		dfs(to_string(i), 1);
		visited[i] = false;
	}

	return 0;
}