#include <bits/stdc++.h>
using namespace std;

int N;
int A[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		for (int i = 0; i < 100; i++) {
			cin >> A[i];
		}

		while(N--) {
			sort(A, A + 100);
			A[99]--;
			A[0]++;
		}
		sort(A, A + 100);
		int answer = A[99] - A[0];
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}