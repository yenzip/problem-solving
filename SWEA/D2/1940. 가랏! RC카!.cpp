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
		int answer = 0;	// �̵� �Ÿ�
		int speed = 0;	// ���� �ӵ�
		for (int i = 0; i < N; i++) {
			cin >> cmd;
			if (cmd != 0) {
				cin >> acc;
				if (cmd == 1) {	// ���ӵ�
					speed += acc;
				}
				else {	// ���ӵ�
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