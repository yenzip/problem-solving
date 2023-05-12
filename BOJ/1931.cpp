#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);	// { start, end }

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		cin >> A[i].second;
	}

	sort(A.begin(), A.end(), compare);

	int answer = 0;
	int end = -1;
	for (int i = 0; i < N; i++) {
		if (end <= A[i].first) {
			end = A[i].second;
			answer++;
		}
	}

	cout << answer;

	return 0;
}