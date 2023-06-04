#include <bits/stdc++.h>
using namespace std;

int N, M, card;
unordered_map<int, int> um;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> card;
		um[card]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> card;
		if (um.find(card) == um.end()) {
			cout << "0 ";
		}
		else {
			cout << um[card] << " ";
		}
	}

	return 0;
}