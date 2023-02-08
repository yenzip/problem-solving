#include <bits/stdc++.h>

using namespace std;

int alphabet[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
	string A, B;
	cin >> A >> B;

	vector<int> v;
	for (int i = 0; i < A.size(); i++) {
		v.push_back(alphabet[A[i] - 'A']);
		v.push_back(alphabet[B[i] - 'A']);
	}

	while (v.size() > 2) {
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = (v[i] + v[i + 1]) % 10;
		}
		v.resize(v.size() - 1);
	}

	cout << v[0] << v[1];

	return 0;
}