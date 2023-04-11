#include <bits/stdc++.h>
using namespace std;

int P, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> P >> K;
	cout << abs(P - K) + 1;

	return 0;
}