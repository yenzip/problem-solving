#include <bits/stdc++.h>
using namespace std;

int N, C;
int A[1001];
map<int, pair<int, int>> m;	// { value, { index, count} }

bool compare(int a, int b) {
	if (m[a].second == m[b].second) {
		return m[a].first < m[b].first;
	}
	return m[a].second > m[b].second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (m[A[i]].first == 0) {
			m[A[i]].first = i;
		}
		else {
			m[A[i]].first = min(m[A[i]].first, i);
		}
		m[A[i]].second++;
	}
	
	sort(A + 1, A + N + 1, compare);

	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}

	return 0;
}