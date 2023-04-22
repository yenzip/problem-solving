#include <bits/stdc++.h>
using namespace std;

int TC, N;
int p[20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p[i];
		}

		int answer = 0;
		for (int i = 1; i < N - 1; i++) {
			if (p[i - 1] < p[i] && p[i] < p[i + 1] || p[i - 1] > p[i] && p[i] > p[i + 1]) {
				answer++;
			}
		}
		cout << '#' << t << ' ' << answer << '\n';
 	}

	return 0;
}