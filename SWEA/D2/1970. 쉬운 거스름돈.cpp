#include <bits/stdc++.h>
using namespace std;

int T, money;
int m50000, m10000, m5000, m1000, m500, m100, m50, m10;


void calc() {
	m50000 = money / 50000;	// 1. 50000원
	if (m50000) {
		money -= 50000 * m50000;
	}
	
	m10000 = money / 10000;	// 2. 10000원
	if (m10000) {
		money -= 10000 * m10000;
	}
	
	m5000 = money / 5000;	// 3. 5000원
	if (m5000) {
		money -= 5000 * m5000;
	}

	m1000 = money / 1000;	// 4. 1000원
	if (m1000) {
		money -= 1000 * m1000;
	}

	m500 = money / 500;	// 5. 500원
	if (m500) {
		money -= 500 * m500;
	}

	m100 = money / 100;	// 6. 100원
	if (m100) {
		money -= 100 * m100;
	}

	m50 = money / 50;	// 7. 50원
	if (m50) {
		money -= 50 * m50;
	}

	m10 = money / 10;	// 8. 10원
	if (m10) {
		money -= 10 * m10;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> money;
		cout << '#' << t << '\n';
		calc();
		cout << m50000 << ' ' << m10000 << ' ' << m5000 << ' ' << m1000 << ' ' << m500 << ' ' << m100 << ' ' << m50 << ' ' << m10 << ' ' << '\n';
	}
	
	return 0;
}