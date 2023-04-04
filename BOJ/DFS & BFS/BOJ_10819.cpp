#include <bits/stdc++.h>
using namespace std;

int N;
int A[8];
bool visited[8];
int npr[8];
int answer = 0;

int calc() {
	int sum = 0;
	for (int i = 1; i < N; i++) {
		sum += abs(npr[i - 1] - npr[i]);
	}
	return sum;
}

void dfs(int depth) {
	if (depth == N) {
		answer = max(answer, calc());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			npr[depth] = A[i];
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dfs(0);

	cout << answer << '\n';

	return 0;
}