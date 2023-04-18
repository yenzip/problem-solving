#include <bits/stdc++.h>
using namespace std;

int T;
int A[100][100];

int col_sum() {
	int maxVal = 0;
	for (int j = 0; j < 100; j++) {
		int sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += A[i][j];
		}
		maxVal = max(maxVal, sum);
	}
	return maxVal;
}

int diagonal_sum() {
	int sum1 = 0;
	for (int i = 0; i < 100; i++) {
		sum1 += A[i][i];
	}

	int sum2 = 0;
	for (int i = 0; i < 100; i++) {
		sum2 += A[i][100 - i - 1];
	}

	return max(sum1, sum2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 10; t++) {
		cin >> T;

		int answer = 0;
		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				cin >> A[i][j];
				sum += A[i][j];
			}
			answer = max(answer, sum);	// 행 합 구하기
		}
		answer = max(answer, col_sum());	// 열 합 구하기
		answer = max(answer, diagonal_sum());	// 대각선 합 구하기

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}