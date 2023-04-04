#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int year = 0;
	int e = 0, s = 0, m = 0;
	while (!(e == E && s == S && m == M)) {
		e = year % 15 + 1;
		s = year % 28 + 1;
		m = year % 19 + 1;
		year++;
	}

	cout << year << '\n';

	return  0;
}