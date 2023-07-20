#include <bits/stdc++.h>
using namespace std;

int N;
int A[25][25];
bool visited[25][25];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> answer;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	int dist = 0;

	visited[sx][sy] = true;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		dist++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && A[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			A[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] && !visited[i][j]) {
				answer.push_back(bfs(i, j));
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() <<"\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}
