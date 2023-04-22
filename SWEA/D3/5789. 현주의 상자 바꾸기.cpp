#include <bits/stdc++.h>
using namespace std;

int T, N, Q, L, R;
int box[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(box, 0, sizeof(box));
		cin >> N >> Q;
		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;
			for (int j = L; j <= R; j++) {
				box[j] = i;
			}
		}
		cout << '#' << t << ' ';
		for (int i = 1; i <= N; i++) {
			cout << box[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}