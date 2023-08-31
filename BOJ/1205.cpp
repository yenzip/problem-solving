#include <bits/stdc++.h>
using namespace std;

int N, M, P;
long long A[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> P;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int idx = 0;
	int rank = 1;

	while (idx < N && M <= A[idx]) {
		if (M != A[idx]) {
			rank++;
		}
		idx++;
	}

	if (idx < P) {
		cout << rank;
	}
	else {
		cout << -1;
	}

	return 0;
}