#include <bits/stdc++.h>
using namespace std;

bool buttons[10];

int check(string s) {
	int count = 0;
	for (auto c : s) {
		if (!buttons[c - '0']) {
			return -1;
		}
		else {
			count++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	memset(buttons, true, sizeof(buttons));
	for (int i = 0; i < M; i++) {
		int block;
		cin >> block;
		buttons[block] = false;
	}

	int answer = abs(N - 100);
	for (int channel = 0; channel <= 1000000; channel++) {
		string tmp = to_string(channel);
		int count = check(tmp);
		if (count != -1) {
			int move_one = abs(N - channel);	// +/-
			answer = min(answer, count + move_one);
		}
	}

	cout << answer << '\n';

	return 0;
}