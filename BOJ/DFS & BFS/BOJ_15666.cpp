#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];
int npr[8 + 1];
set<vector<int>> s;

void dfs(int start, int depth) {
	if (depth == M) {
		vector<int> tmp;
		for (int i = 1; i <= M; i++) {
			tmp.push_back(npr[i]);
		}
		s.insert(tmp);
		tmp.clear();
		return;
	}

	for (int i = start; i < N; i++) {
		npr[depth + 1] = arr[i];
		dfs(i, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	dfs(0, 0);

	for (auto v : s) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}