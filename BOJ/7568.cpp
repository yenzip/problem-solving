#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;
		A.push_back({ weight, height });
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (A[i].first < A[j].first && A[i].second < A[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
	}

	return 0;
}