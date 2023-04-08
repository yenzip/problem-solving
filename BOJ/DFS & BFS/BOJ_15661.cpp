#include <bits/stdc++.h>
using namespace std;

int N;
int S[20][20];
bool visited[20];
int answer = 1000000000;

int calc() {
	int start = 0;
	int link = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] && visited[j]) {
				start += S[i][j];
			}
			if (!visited[i] && !visited[j]) {
				link += S[i][j];
			}
		}
	}

	return abs(start - link);
}

void dfs(int start, int depth) {
	if (depth == N) {
		return;
	}

	answer = min(answer, calc());

	for (int i = start; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);

	cout << answer << '\n';

	return 0;
}