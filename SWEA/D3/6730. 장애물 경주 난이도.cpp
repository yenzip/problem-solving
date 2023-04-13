#include <bits/stdc++.h>
using namespace std;

int T, N;
int block[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> block[i];
		}
		int up = 0, down = 0;
		for (int i = 1; i < N; i++) {
			if (block[i - 1] < block[i]) {	//올라가기
				up = max(up, block[i] - block[i - 1]);
			}
			else {	// 내려가기
				down = max(down, block[i - 1] - block[i]);
			}
		}
		cout << '#' << t << ' ' << up << ' ' << down << '\n';
	}

	return 0;
}