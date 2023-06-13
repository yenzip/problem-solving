#include <bits/stdc++.h>
using namespace std;

int N, x;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		s.insert(x);
	}

	for (auto ans : s) {
		cout << ans << " ";
	}

	return 0;
}