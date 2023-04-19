#include <bits/stdc++.h>
using namespace std;

int TC, A, B, C;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> A >> B >> C;
		int minVal = min(A, B);
		int maxVal = max(A, B);
		int answer = C / minVal + (C % minVal) / maxVal;
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}