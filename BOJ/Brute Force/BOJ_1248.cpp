#include <bits/stdc++.h>
using namespace std;

int N;
char S[10][10];
int A[10];

bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += A[i];
		if (S[i][idx] == '+' && sum <= 0) {
			return false;
		}
		if (S[i][idx] == '0' && sum != 0) {
			return false;
		}
		if (S[i][idx] == '-' && sum >= 0) {
			return false;
		}
	}
	return true;
}

void go(int depth) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			cout << A[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		A[depth] = i;
		if (check(depth)) {
			go(depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> S[i][j];
		}
	}

	go(0);

	return 0;
}