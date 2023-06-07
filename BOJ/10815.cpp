#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int card;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> card;
		v.push_back(card);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << binary_search(v.begin(), v.end(), card) << " ";
	}

	return 0;
}