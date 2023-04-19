#include <bits/stdc++.h>
using namespace std;

string now;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

bool isOut(int x, int y) {
	return (x < 1 || x > 8 || y < 1 || y > 8);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> now;
	int x = now[0] - 'a', y = now[1] - '1', answer = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny)) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}