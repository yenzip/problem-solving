#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int A[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	int dist = 1;

	visited[sx][sy] = true;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && !A[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				dist++;
			}
		}
	}
	
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				A[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int answer = 0;
	vector<int> area;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!A[i][j] && !visited[i][j]) {
				area.push_back(bfs(i, j));
				answer++;
			}
		}
	}

	cout << answer <<"\n";

	sort(area.begin(), area.end());

	for (auto a : area) {
		cout << a << " ";
	}

	return 0;
}