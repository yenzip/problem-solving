#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		double sum = 0;
		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			sum += num;
		}
		int answer = round(sum / 10);
		cout << "#" << i << " " << answer << '\n';
	}

	return 0;
}