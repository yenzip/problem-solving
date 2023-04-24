#include <bits/stdc++.h>
using namespace std;

int H, W;

pair<int, int> findStart(vector<string> park) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (park[i][j] == 'S') {
				return { i, j };
			}
		}
	}
}

bool isOut(int x, int y) {
	return (x < 0 || x >= H || y < 0 || y >= W);
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;

	H = park.size();
	W = park[0].size();

	auto start = findStart(park);
	int x = start.first, y = start.second;

	for (auto route : routes) {
		char op = route[0];
		int n = route[2] - '0';

		if (op == 'N') {
			if (!isOut(x - n, y)) {
				bool obstacle = false;
				for (int i = 1; i <= n; i++) {
					if (park[x - i][y] == 'X') {
						obstacle = true;
						break;
					}
				}
				if (!obstacle) {
					x -= n;
				}
			}
		}
		if (op == 'S') {
			if (!isOut(x + n, y)) {
				bool obstacle = false;
				for (int i = 1; i <= n; i++) {
					if (park[x + i][y] == 'X') {
						obstacle = true;
						break;
					}
				}
				if (!obstacle) {
					x += n;
				}
			}
		}
		if (op == 'W') {
			if (!isOut(x, y - n)) {
				bool obstacle = false;
				for (int i = 1; i <= n; i++) {
					if (park[x][y - i] == 'X') {
						obstacle = true;
						break;
					}
				}
				if (!obstacle) {
					y -= n;
				}
			}
		}
		if (op == 'E') {
			if (!isOut(x, y + n)) {
				bool obstacle = false;
				for (int i = 1; i <= n; i++) {
					if (park[x][y + i] == 'X') {
						obstacle = true;
						break;
					}
				}
				if (!obstacle) {
					y += n;
				}
			}
		}
	}

	answer.push_back(x);
	answer.push_back(y);

	return answer;
}