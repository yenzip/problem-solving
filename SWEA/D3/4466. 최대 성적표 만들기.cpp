#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int score[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}
		sort(score, score + N, greater<int>());

		int answer = 0;
		for (int i = 0; i < K; i++) {
			answer += score[i];
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}