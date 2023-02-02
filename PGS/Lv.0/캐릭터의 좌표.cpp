#include <string>
#include <vector>

using namespace std;

int dRow[4] = { 0, 0, -1, 1 };	// »óÇÏÁÂ¿ì
int dCol[4] = { 1, -1, 0, 0 };


vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> answer;
	int row = 0, col = 0;

	for (auto key : keyinput) {
		int nextRow;
		int nextCol;

		if (key == "up") {
			nextRow = row + dRow[0];
			nextCol = col + dCol[0];
		}
		else if (key == "down") {
			nextRow = row + dRow[1];
			nextCol = col + dCol[1];
		}
		else if (key == "left") {
			nextRow = row + dRow[2];
			nextCol = col + dCol[2];
		}
		else if (key == "right") {
			nextRow = row + dRow[3];
			nextCol = col + dCol[3];
		}

		if ((nextRow >= 0 - board[0] / 2 && nextRow <= board[0] / 2) && (nextCol >= 0 - board[1] / 2 && nextCol <= board[1] / 2)) {
			row = nextRow;
			col = nextCol;
		}
	}

	answer.push_back(row);
	answer.push_back(col);

	return answer;
}