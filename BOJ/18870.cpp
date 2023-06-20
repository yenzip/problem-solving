#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> X;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	X.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		v.push_back(X[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), X[i]) - v.begin() << " ";
	}

	return 0;
}