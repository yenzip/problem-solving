#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> board(rows, vector<int>(columns, 0));
	for (int i = 0, num = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j] = ++num;
		}
	}

	vector<vector<int>> tmp;	// board บนป็
	tmp.assign(board.size(), vector<int>(board.size()));
	copy(board.begin(), board.end(), tmp.begin());

	for (auto query : queries) {
		int mini = rows * columns + 1;
		int sx = query[0] - 1, sy = query[1] - 1;
		int ex = query[2] - 1, ey = query[3] - 1;

		int x = sx, y = sy;
		while (++y <= ey) {
			tmp[x][y] = board[x][y - 1];
			mini = min(mini, tmp[x][y]);
		}
		y--;

		while (++x <= ex) {
			tmp[x][y] = board[x - 1][y];
			mini = min(mini, tmp[x][y]);
		}
		x--;

		while (--y >= sy) {
			tmp[x][y] = board[x][y + 1];
			mini = min(mini, tmp[x][y]);
		}
		y++;

		while (--x >= sx) {
			tmp[x][y] = board[x + 1][y];
			mini = min(mini, tmp[x][y]);
		}

		copy(tmp.begin(), tmp.end(), board.begin());
		answer.push_back(mini);
	}

	return answer;
}