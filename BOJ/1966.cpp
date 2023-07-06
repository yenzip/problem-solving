#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int imp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> M;

		queue<pair<int, int>> q;	// { index, importance }
		priority_queue<int> pq;	// { importance }

		for (int i = 0; i < N; i++) {
			cin >> imp;
			q.push({ i, imp });
			pq.push(imp);
		}

		int answer = 1;

		while (!q.empty()) {
			int index = q.front().first;
			int importance = q.front().second;
			q.pop();

			if (importance == pq.top()) {
				if (index == M) {
					break;
				}
				pq.pop();
				answer++;
			}
			else {
				q.push({ index, importance });
			}
		}

		cout << answer << "\n";
	}

	return 0;
}