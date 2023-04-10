#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int S;
bool visited[MAX][MAX];

struct info {
	int screen;
	int clipboard;
	int time;
};

bool isOut(int x) {
	return (x < 0 || x > MAX);
}

void bfs(int s, int c) {
	queue<info> q;
	visited[s][c] = true;
	q.push({ s, c, 0 });

	while (!q.empty()) {
		int s = q.front().screen;
		int c = q.front().clipboard;
		int t = q.front().time;
		q.pop();

		if (s == S) {
			cout << t << '\n';
			return;
		}

		if (!isOut(s) && !visited[s][s]) {	// 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
			visited[s][s] = true;
			q.push({ s, s, t + 1 });
		}
		if (!isOut(s + c) && !visited[s + c][c]) {	// 2. 클립보드에 있는 이모티콘을 화면에 붙여넣기
			visited[s + c][c] = true;
			q.push({ s + c, c, t + 1 });
		}
		if (!isOut(s - 1) && !visited[s - 1][c]) {	// 3. 화면에 있는 이모티콘 하나 삭제
			visited[s - 1][c] = true;
			q.push({ s - 1, c, t + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;

	bfs(1, 0);

	return 0;
}