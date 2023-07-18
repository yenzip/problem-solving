#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	int dist;
};

struct Compare {
	bool operator()(Point a, Point b) {
		if (a.dist == b.dist) {		// 2. �Ÿ��� ���ٸ� ���� ���� �ִ� ����� ����
			if (a.x == b.x) {		// 3. ���� ���� �ִٸ� ���� ���� ����� ����
				return a.y > b.y;
			}
			return a.x > b.x;
		}
		return a.dist > b.dist;		// 1. �Ÿ��� ���� ����� ����� ����
	}
};

int N;
int x, y;
int A[20][20];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<vector<Point>> fish;	// ����� ũ�⺰ ��ǥ

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int bfs(int sx, int sy, int ex, int ey, int limit) {	// �ִ� �Ÿ� ���ϱ�
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

	int answer = 0;	// ���� ���� ������ ��û���� �ʰ� ����⸦ ��� �Դ� �ð�
	int size = 2;	// �Ʊ� ��� ũ��
	int eat = 0;	// �Ʊ� �� ��� ���� ����� ��
	
	while (true) {
		priority_queue<Point, vector<Point>, Compare> pq;

		for (int i = 1; i < size; i++) {
			for (auto p : fish[i]) {
				if (A[p.x][p.y]) {
					p.dist = bfs(x, y, p.x, p.y, size);	// �ִ� �Ÿ� ���ϱ�
					if (p.dist == -1) {	// �ش� ��ǥ�� �� �� ����
						continue;
					}
					pq.push({ p.x, p.y, p.dist });
				}
			}
		}

		if (pq.empty()) {	// �� �̻� ���� �� �ִ� ����Ⱑ ����
			break;
		}

		A[pq.top().x][pq.top().y] = 0;	// ����� ��� ����
		x = pq.top().x;
		y = pq.top().y;
		answer += pq.top().dist;	// �Ÿ� ���ϱ�
		eat++;
		pq.pop();

		if (size < 7 && eat == size) {	// ��� ���� ����� ���� �Ʊ� ����� ũ��� ���ٸ� ũ�� 1 ����
			size++;
			eat = 0;
		}
	}

	cout << answer;

	return 0;
}