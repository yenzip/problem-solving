#include <bits/stdc++.h>
using namespace std;

int T, N;
bool visited[10];

bool check() {
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void go(int n) {
	int tmp = n;
	while (tmp) {
		if (!visited[tmp % 10]) {
			visited[tmp % 10] = true;
		}
		tmp /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		memset(visited, false, sizeof(visited));
		int answer;
		for (answer = N; ; answer += N) {
			if (check()) {
				break;
			}
			go(answer);
		}
		cout << '#' << i << ' ' << answer - N << '\n';
	}

	return 0;
}