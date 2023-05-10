#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, A[i].second - i);
	}

	cout << answer + 1;

	return 0;
}