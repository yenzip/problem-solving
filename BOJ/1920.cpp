#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;
		cout << binary_search(A.begin(), A.end(), target) << "\n";
	}

	return 0;
}