#include <bits/stdc++.h>
using namespace std;

int T, N;
int file[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<int> sub(N);
		for (int i = 0; i < N; i++) {
			cin >> file[i];
		}
		int avg = (accumulate(file, file + N, 0)) / N;
		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (file[i] < avg) {
				answer += avg - file[i];
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}