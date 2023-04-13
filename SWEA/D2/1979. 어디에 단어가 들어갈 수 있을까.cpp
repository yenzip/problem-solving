#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int board[15][15];
int answer;

int check_width(int idx) {
	int cnt = 0;
	string word = string(K, '1');
	string s;
	for (int i = 0; i < N; i++) {
		s += (board[idx][i] + '0');
	}
	
	for (int i = 0; i <= N - K; i++) {
		if (word.compare(s.substr(i, K)) == 0) {
			if ((i - 1 >= 0 && board[idx][i - 1]) || (i + K < N && board[idx][i + K])) {
				continue;
			}
			cnt++;
		}
	}
	return cnt;
}

int check_height(int idx) {
	int cnt = 0;
	string word = string(K, '1');
	string s;
	for (int i = 0; i < N; i++) {
		s += (board[i][idx] + '0');
	}

	for (int i = 0; i <= N - K; i++) {
		if (word.compare(s.substr(i, K)) == 0) {
			if ((i - 1 >= 0 && board[i - 1][idx]) || (i + K < N && board[i + K][idx])) {
				continue;
			}
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		answer = 0;
		for (int i = 0; i < N; i++) {
			answer += check_width(i);
			answer += check_height(i);
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}