#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
	string s = to_string(num);
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<bool> A(1003001 + 1, true);
	A[1] = false;
	for (int i = 2; i * i <= 1003001; i++) {
		if (A[i]) {
			for (int j = i * 2; j <= 1003001; j += i) {
				A[j] = false;
			}
		}
	}

	int answer = 0;
	for (int i = N; ; i++) {
		if (A[i] && isPalindrome(i)) {
			answer = i;
			break;
		}
	}

	cout << answer;

	return 0;
}