#include <bits/stdc++.h>
using namespace std;

int T, N;
int cmd, acc;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int answer = 0;	// 이동 거리
		int speed = 0;	// 현재 속도
		for (int i = 0; i < N; i++) {
			cin >> cmd;
			if (cmd != 0) {
				cin >> acc;
				if (cmd == 1) {	// 가속도
					speed += acc;
				}
				else {	// 감속도
					if (speed < acc) {
						speed = 0;
					}
					else {
						speed -= acc;
					}
				}
			}
			answer += speed;
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}