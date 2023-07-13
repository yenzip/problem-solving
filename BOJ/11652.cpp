#include <bits/stdc++.h>
using namespace std;

int N;
long long card;
map<long long, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> card;
		m[card]++;
	}

	long long answer = LLONG_MAX;
	int maxVal = 0;

	for (auto v : m) {
		if (maxVal < v.second) {
			answer = v.first;
			maxVal = v.second;
		}
		else if (maxVal == v.second) {
			answer = min(answer, v.first);
		}
	}

	cout << answer;

	return 0;
}