#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M;
int D[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	fill(&D[1][1], &D[N][N], INF);
	for (int i = 1; i <= N; i++) {
		D[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		D[A][B] = D[B][A] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				D[s][e] = min(D[s][e], D[s][k] + D[k][e]);
			}
		}
	}

	int answer, min_value = INF;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += D[i][j];
		}
		if (sum < min_value) {
			answer = i;
			min_value = sum;
		}
	}

	cout << answer;

	return 0;
}