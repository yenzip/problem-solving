#include <bits/stdc++.h>
using namespace std;

int N, M, x;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> x;
		m[x]++;
	}

	int answer = 0;

	for(auto &entry : m) {
		if (entry.second == 1) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}