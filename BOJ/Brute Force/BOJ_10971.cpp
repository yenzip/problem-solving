#include <bits/stdc++.h>
using namespace std;

int N;
int W[10][10];
int arr[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
		arr[i] = i;
	}

	int answer = 10000000;
	do {
		bool no_way = false;
		int cost = 0;
		for (int i = 1; i < N; i++) {
			if (!W[arr[i - 1]][arr[i]]) {
				no_way = true;
				break;
			}
			cost += W[arr[i - 1]][arr[i]];
		}
		if (!no_way && W[arr[N - 1]][arr[0]]) {
			answer = min(answer, cost + W[arr[N - 1]][arr[0]]);
		}
	} while (next_permutation(arr, arr + N));

	cout << answer << '\n';

	return 0;
}