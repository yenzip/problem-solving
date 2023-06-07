#include <bits/stdc++.h>
using namespace std;

int N, M, x;
vector<int> A, B;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back(x);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		cin >> x;
		B.push_back(x);
	}

	sort(B.begin(), B.end());

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!binary_search(B.begin(), B.end(), A[i])) {
			cnt++;
			answer.push_back(A[i]);

		}
	}

	cout << cnt << "\n";
	for (auto ans : answer) {
		cout << ans << " ";
	}
	
	return 0;

}