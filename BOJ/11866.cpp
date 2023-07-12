#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> q;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		answer.push_back(q.front());
		q.pop();
	}
	
	cout << "<";
	for (int i = 0; i < N; i++) {
		cout << answer[i];
		if (i < N - 1) {
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}