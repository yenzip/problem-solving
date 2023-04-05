#include <bits/stdc++.h>
using namespace std;

int N;
int arr[8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	do {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(arr, arr + N));

	return 0;
}