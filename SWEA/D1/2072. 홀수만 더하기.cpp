#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int i = 1; i <= T; i++) {
		int answer = 0;
		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
			if (num % 2) {
				answer += num;
			}
		}
		cout << "#" << i << " " << answer << '\n';
	}

	return 0;
}