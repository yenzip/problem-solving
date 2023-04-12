#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[7][7];
int A_90[7][7];
int A_180[7][7];
int A_270[7][7];

void rotation(int A[7][7], int B[7][7]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0, k = N - 1; j < N; j++, k--) {
			B[i][j] = A[k][i];
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A_90[i][j];
		}
		cout << ' ';
		for (int j = 0; j < N; j++) {
			cout << A_180[i][j];
		}
		cout << ' ';
		for (int j = 0; j < N; j++) {
			cout << A_270[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}
		rotation(A, A_90);
		rotation(A_90, A_180);
		rotation(A_180, A_270);

		cout << '#' << t << '\n';
		print();
	}

	return 0;
}