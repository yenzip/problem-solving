#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		int maxVal = -1;
		for (int i = 0; i < 10; i++) {
			int num;
			cin >> num;
			maxVal = max(maxVal, num);
		}
		cout << "#" << i << " " << maxVal << '\n';
	}

	return 0;
}