#include <bits/stdc++.h>
using namespace std;

int T, N;
int answer;

void go(int now) {
	if (now < 0) {
		return;
	}
	if (now == 0) {
		answer++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (now - i >= 0) {
			go(now - i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		answer = 0;
		go(N);
		cout << answer << '\n';
	}

	return 0;
}