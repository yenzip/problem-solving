#include <bits/stdc++.h>
using namespace std;

int V, E;
typedef tuple<int, int, int> edge;
vector<edge> edges;
vector<int> parents;

bool compare(edge &a, edge &b) {
	return get<2>(a) < get<2>(b);
}

int find_parent(int x) {
	if (x == parents[x]) {
		return x;
	}
	return parents[x] = find_parent(parents[x]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a != b) {
		parents[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	parents.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back(make_tuple(A, B, C));
	}

	sort(edges.begin(), edges.end(), compare);

	int answer = 0;
	for (int i = 0; i < E; i++) {
		edge e = edges[i];
		int a = get<0>(e);
		int b = get<1>(e);
		int c = get<2>(e);
		if (find_parent(a) != find_parent(b)) {
			union_parent(a, b);
			answer += c;
		}
	}

	cout << answer;

	return 0;
}