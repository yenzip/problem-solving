#include <bits/stdc++.h>
using namespace std;

int A[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> A[0] >> A[1] >> A[2];

		sort(A, A + 3, greater<int>());	// 내림차순

		if (A[0] == 0) {
			break;
		}

		if (A[0] >= A[1] + A[2]) {
			cout << "Invalid\n";
		}
		else {
			if (A[0] == A[1] && A[0] == A[2]) {
				cout << "Equilateral\n";
			}
			else if (A[0] == A[1] || A[1] == A[2]) {
				cout << "Isosceles\n";
			}
			else {
				cout << "Scalene\n";
			}
		}
	}

	return 0;
}