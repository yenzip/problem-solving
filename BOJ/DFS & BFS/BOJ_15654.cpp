#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];
bool visited[8];
int npr[9];	

void dfs(int depth) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << npr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			npr[depth + 1] = arr[i];
			dfs(depth + 1);
			visited[i] = false;
		}
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

	dfs(0);

	return 0;
}