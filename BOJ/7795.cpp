#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;
vector<int> A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> M;

		A = vector<int>(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		B = vector<int>(M);
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		sort(A.begin(), A.begin());
		sort(B.begin(), B.end());

		int answer = 0;

		for (int i = 0; i < N; i++) {
			answer += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
		}

		cout << answer << "\n";
	}

	return 0;
}