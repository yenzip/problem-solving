#include <bits/stdc++.h>
using namespace std;

int N;
int D[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> D[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (D[s][k] && D[k][e]) {
					D[s][e] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}