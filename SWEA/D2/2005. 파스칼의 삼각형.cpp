#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[10][10];

void triangle() {
	int i = 0, j = 0;	// 1. 1열 1 채우기
	while (i < N) {
		A[i++][j] = 1;
	}

	i = 1, j = 1;	// 2. 대각선 1 채우기
	while (i < N) {
		A[i++][j++] = 1;
	}
	
	for (int i = 2; i < N; i++) {	// 3. 빈칸(0) 채우기
		for (int j = 1; j < i; j++) {
			if (!A[i][j]) {
				A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
			}
		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cout << A[i][j] << ' ';
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
		memset(A, 0, sizeof(A));
		triangle();
		cout << '#' << t << '\n';
		print();
	}

	return 0;
}