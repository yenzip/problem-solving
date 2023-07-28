#include <bits/stdc++.h>
using namespace std;

struct POS {	
	int x;
	int y;
	int close;	// 좋아하는 학생의 수
	int empty;	// 비어있는 칸의 수
};

struct COMP {
	bool operator()(POS a, POS b) {
		if (a.close == b.close) {
			if (a.empty == b.empty) {
				if (a.x == b.x) {
					return a.y > b.y;
				}
				return a.x > b.x;
			}
			return a.empty < b.empty;
		}
		return a.close < b.close;
	}
};

int N;
bool Like[401][401];	// 좋아하는 학생
int A[20][20];			// 학생 배치
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void arrangeSeat(int num) {	// 자리 배치
	priority_queue<POS, vector<POS>, COMP> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 0) {	// 이미 좌석 배정이 끝났다면
				continue;
			}

			int x = i;
			int y = j;
			int empty = 0;
			int close = 0;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (isOut(nx, ny)) {
					continue;
				}

				if (A[nx][ny] == 0) {
					empty++;
				}
				else if (Like[num][A[nx][ny]]) {
					close++;
				}
			}
			pq.push({ x, y, close, empty });
		}
	}

	A[pq.top().x][pq.top().y] = num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	queue<int> q;		// 학생 순서

	for (int i = 0; i < N * N; i++) {
		int a, b;
		cin >> a;
		q.push(a);
		for (int j = 0; j < 4; j++) {
			cin >> b;
			Like[a][b] = true;
		}
	}

	while (!q.empty()) {
		arrangeSeat(q.front());	// 자리 배치
		q.pop();
	}

	int answer = 0;

	for (int i = 0; i < N; i++) {	// 학생의 만족도 구하기
		for (int j = 0; j < N; j++) {
			int x = i;
			int y = j;
			int num = A[x][y];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (!isOut(nx, ny) && Like[num][A[nx][ny]]) {
					cnt++;
				}
			}
			answer += pow(10, cnt - 1);
		}
	}

	cout << answer;

	return 0;
}