#include <bits/stdc++.h>
using namespace std;

int T, m, d;
int day[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int result[7] = { 4, 5, 6, 0, 1, 2, 3 };	// 금 토 일 월 화 수 목

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> m >> d;
		int sum = accumulate(day, day + m, 0);
		sum += d;
		int answer = result[(sum - 1) % 7];
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}