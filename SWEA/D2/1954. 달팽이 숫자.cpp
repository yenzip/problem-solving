#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[10][10];

void snail() {
	int i = 0, j = 0, num = 1;
	while (num <= N * N) {
		while (j < N && A[i][j] == 0) {
			A[i][j++] = num++;
		}
		i++;	j--;

		while (i < N && A[i][j] == 0) {
			A[i++][j] = num++;
		}
		i--;	j--;

		while (j >= 0 && A[i][j] == 0) {
			A[i][j--] = num++;
		}
		i--;	j++;

		while (i >= 0 && A[i][j] == 0) {
			A[i--][j] = num++;
		}
		i++;	j++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(A, 0, sizeof(A));
		snail();
		cout << '#' << t << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << A[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}