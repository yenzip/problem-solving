#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<string> card(1000);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> card[i];
		}

		deque<string> dq1, dq2;
		if (N % 2) {	// 圈荐 贸府
			for (int i = 0; i < N; i++) {
				if (i <= N / 2) {
					dq1.push_back(card[i]);
				}
				else {
					dq2.push_back(card[i]);
				}
			}
		}
		else {	// 娄荐 贸府
			for (int i = 0; i < N; i++) {
				if (i < N / 2) {
					dq1.push_back(card[i]);
				}
				else {
					dq2.push_back(card[i]);
				}
			}
		}

		vector<string> answer;
		for (int i = 0; i < N / 2; i++) {
			answer.push_back(dq1.front());
			dq1.pop_front();
			answer.push_back(dq2.front());
			dq2.pop_front();
		}
		if (!dq1.empty()) {
			answer.push_back(dq1.front());
			dq1.pop_front();
		}

		cout << '#' << t << ' ';
		for (auto ans : answer) {
			cout << ans << ' ';
		}
		cout << '\n';
	}

	return 0;
}