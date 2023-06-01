#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> A;

bool comp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N ;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		A.push_back(word);
	}

	sort(A.begin(), A.end(), comp);

	cout << A[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (A[i] == A[i - 1]) {
			continue;
		}
		cout << A[i] << "\n";
	}

	return 0;
}