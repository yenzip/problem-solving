#include <bits/stdc++.h>
using namespace std;

#define INF 501
int N, M;
vector<vector<int>> d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	d.resize(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		d[A][B] = 1;
	}

	for (int k = 1; k <= N; k++) {	// Floyd-Warshall
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
			}
		}
	}

	int result = 0;	// 순위를 정확히 알 수 있는 학생 수
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (d[i][j] != INF || d[j][i] != INF) {
				count++;
			}
		}
		if (count == N) {
			result++;
		}
	}

	cout << result << '\n';

	return 0;
}