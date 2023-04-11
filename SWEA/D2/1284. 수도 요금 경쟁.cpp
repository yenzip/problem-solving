#include <bits/stdc++.h>
using namespace std;

int T;
int P, Q, R, S, W;
int A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> P >> Q >> R >> S >> W;
		A = P * W;
		B = W <= R ? Q : Q + (W - R) * S;
		cout << '#' << i << ' ' << (A < B ? A : B) << '\n';
	}

	return 0;
}