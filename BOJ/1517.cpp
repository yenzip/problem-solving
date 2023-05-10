#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> tmp;
long long answer = 0;

void merge(int s, int m, int e) {
	int i = s, j = m + 1, k = s;

	while (i <= m && j <= e) {
		if (A[i] <= A[j]) {
			tmp[k++] = A[i++];
		}
		else {	// swap
			tmp[k] = A[j];
			answer += j - k;
			j++;
			k++;
		}
	}

	while (i <= m) {
		tmp[k++] = A[i++];
	}

	while (j <= e) {
		tmp[k++] = A[j++];
	}

	for (int i = s; i <= e; i++) {
		A[i] = tmp[i];
	}
}

void merge_sort(int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		merge_sort(s, m);
		merge_sort(m + 1, e);
		merge(s, m, e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	A.resize(N);
	tmp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	merge_sort(0, N - 1);

	cout << answer;

	return 0;
}