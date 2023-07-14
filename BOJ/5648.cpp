#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long A[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		A[i] = stoll(s);
	}

	sort(A, A + n);

	for (int i = 0; i < n; i++) {
		cout << A[i] << "\n";
	}

	return 0;
}
