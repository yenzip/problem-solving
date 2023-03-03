#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> map;
int dX[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void unsafe(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nX = x + dX[i];
		int nY = y + dY[i];

		if (isOut(nX, nY) || map[nX][nY] == 1) {
			continue;
		}

		map[nX][nY] = 1;
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	N = board.size();
	map.insert(map.begin(), board.begin(), board.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				unsafe(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				answer++;
			}
		}
	}

	return answer;
}