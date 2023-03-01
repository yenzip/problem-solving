#include <string>
#include <vector>

using namespace std;

int dX[4] = { 0, 0, -1, 1 };	// up - down - left - right
int dY[4] = { 1, -1, 0, 0 };

int isOut(int x, int y, int N, int M) {
	return (x < 0 - N / 2 || x > N / 2 || y < 0 - M / 2 || y > M / 2);
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> answer;

	int x = 0, y = 0;
	for (auto key : keyinput) {
		if (key == "up" && !isOut(x + dX[0], y + dY[0], board[0], board[1])) {
			y += dY[0];
		}
		else if (key == "down" && !isOut(x + dX[1], y + dY[1], board[0], board[1])) {
			y += dY[1];
		}
		else if (key == "left" && !isOut(x + dX[2], y + dY[2], board[0], board[1])) {
			x += dX[2];
		}
		else if (key == "right" && !isOut(x + dX[3], y + dY[3], board[0], board[1])) {
			x += dX[3];
		}
	}

	answer.push_back(x);
	answer.push_back(y);

	return answer;
}