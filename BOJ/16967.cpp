#include <bits/stdc++.h>
using namespace std;

int H, W, X, Y;
int A[300][300];
int B[600][600];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			A[i][j] = B[i][j];
		}
	}

	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			A[i][j] -= A[i - X][j - Y];
		}
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}