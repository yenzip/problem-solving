#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	int dist;
};

struct Compare {
	bool operator()(Point a, Point b) {
		if (a.dist == b.dist) {		// 2. 거리가 같다면 가장 위에 있는 물고기 선택
			if (a.x == b.x) {		// 3. 가장 위에 있다면 가장 왼쪽 물고기 선택
				return a.y > b.y;
			}
			return a.x > b.x;
		}
		return a.dist > b.dist;		// 1. 거리가 가장 가까운 물고기 선택
	}
};

int N;
int x, y;
int A[20][20];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<Point>> fish;	// 물고기 크기별 좌표

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int bfs(int sx, int sy, int ex, int ey, int limit) {	// 최단 거리 구하기
	bool visited[20][20] = { false, };
	queue<Point> q;

	visited[sx][sy] = true;
	q.push({ sx, sy, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		if (x == ex && y == ey) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && !visited[nx][ny] && A[nx][ny] <= limit || A[nx][ny] == 9) {
				visited[nx][ny] = true;
				q.push({ nx, ny, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	fish.resize(7);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];

			if (A[i][j] == 9) {
				x = i;
				y = j;
			}
			else if (A[i][j]) {
				fish[A[i][j]].push_back({ i, j, 0 });
			}
		}
	}

	int answer = 0;	// 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아 먹는 시간
	int size = 2;	// 아기 상어 크기
	int eat = 0;	// 아기 상어가 잡아 먹은 물고기 수
	
	while (true) {
		priority_queue<Point, vector<Point>, Compare> pq;

		for (int i = 1; i < size; i++) {
			for (auto p : fish[i]) {
				if (A[p.x][p.y]) {
					p.dist = bfs(x, y, p.x, p.y, size);	// 최단 거리 구하기
					if (p.dist == -1) {	// 해당 좌표로 갈 수 없음
						continue;
					}
					pq.push({ p.x, p.y, p.dist });
				}
			}
		}

		if (pq.empty()) {	// 더 이상 먹을 수 있는 물고기가 없음
			break;
		}

		A[pq.top().x][pq.top().y] = 0;	// 물고기 잡아 먹음
		x = pq.top().x;
		y = pq.top().y;
		answer += pq.top().dist;	// 거리 더하기
		eat++;
		pq.pop();

		if (size < 7 && eat == size) {	// 잡아 먹은 물고기 수가 아기 상어의 크기와 같다면 크기 1 증가
			size++;
			eat = 0;
		}
	}

	cout << answer;

	return 0;
}