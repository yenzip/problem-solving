#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent;

int findParent(int x) {	// find
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {	// union
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

void checkParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {	// union
			unionParent(a, b);
		}
		else {
			checkParent(a, b);
		}
	}

	return 0;
}