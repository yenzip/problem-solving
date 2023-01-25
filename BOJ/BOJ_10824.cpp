#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C, D;
	string sAB, sCD;

	cin >> A >> B >> C >> D;

	sAB = to_string(A) + to_string(B);
	sCD = to_string(C) + to_string(D);

	cout << stoll(sAB) + stoll(sCD);

	return 0;
}