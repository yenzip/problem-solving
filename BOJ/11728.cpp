#include <bits/stdc++.h>
using namespace std;

int N, M, x;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x;
		answer.push_back(x);
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		answer.push_back(x);
	}

	sort(answer.begin(), answer.end());

	for (auto a : answer) {
		cout << a << " ";
	}

	return 0;
}