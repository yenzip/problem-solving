#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string s = to_string(N);
	vector<int> A(s.size());
	for (int i = 0; i < s.size(); i++) {
		A[i] = s[i] - '0';
	}

	for (int i = 0; i < s.size(); i++) {
		int max = i;
		for (int j = i + 1; j < s.size(); j++) {
			if (A[max] < A[j])
				max = j;
		}
		swap(A[i], A[max]);
	}

	for (int i = 0; i < s.size(); i++) {
		cout << A[i];
	}

	return 0;
}