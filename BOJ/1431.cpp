#include <bits/stdc++.h>
using namespace std;

int N;
string S[50];

int sum(string s) {
	int result = 0;

	for (auto c : s) {
		if (c >= '0' && c <= '9') {
			result += c - '0';
		}
	}

	return result;
}

bool compare(string A, string B) {
	if (A.length() == B.length()) {
		if (sum(A) == sum(B)) {
			return A < B;
		}
		return sum(A) < sum(B);
	}
	return A.length() < B.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	sort(S, S + N, compare);

	for (int i = 0; i < N; i++) {
		cout << S[i] << "\n";
	}

	return 0;
}