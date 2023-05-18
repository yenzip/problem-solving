#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M;
typedef tuple<int, int, int> edge;
vector<edge> edges;
vector<long long> D;

void bellman_ford(int s) {
	D[s] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			edge e = edges[j];
			int start = get<0>(e);
			int end = get<1>(e);
			int weight = get<2>(e);
			if (D[start] != INF && D[end] > D[start] + weight) {
				D[end] = D[start] + weight;
			}
		}
	}

	bool mCycle = false;
	for (int i = 0; i < M; i++) {
		edge e = edges[i];
		int start = get<0>(e);
		int end = get<1>(e);
		int weight = get<2>(e);
		if (D[start] != INF && D[end] > D[start] + weight) {
			mCycle = true;
			break;
		}
	}

	if (mCycle) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (D[i] == INF) {
				cout << "-1\n";
			}
			else {
				cout << D[i] << "\n";
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	D.resize(N + 1, INF);
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back(make_tuple(A, B, C));
	}

	bellman_ford(1);

	return 0;
}