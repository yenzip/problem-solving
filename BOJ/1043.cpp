#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<int> truth;
vector<vector<int>> party;
vector<int> parent;

int findParent(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	truth.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> truth[i];
	}

	party.resize(M);
	for (int i = 0; i < M; i++) {
		int size;
		cin >> size;
		party[i].resize(size);
		for (int j = 0; j < size; j++) {
			cin >> party[i][j];
		}
	}

	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 1; j < party[i].size(); j++) {
			unionParent(party[i][j - 1], party[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < M; i++) {
		bool isPossible = true;
		for (int j = 0; j < T; j++) {
			if (findParent(party[i][0]) == findParent(truth[j])) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}