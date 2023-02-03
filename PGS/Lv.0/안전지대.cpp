#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool visited[100][100];
int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int danger = 0;

int isOut(int row, int col) {
	return (row < 0 || row >= N || col < 0 || col >= M);
}

void check(vector<vector<int>> board, int row, int col) {
	visited[row][col] = true;
	danger++;

	for (int i = 0; i < 8; i++) {
		int nextRow = row + dRow[i];
		int nextCol = col + dCol[i];

		if (!isOut(nextRow, nextCol) && board[nextRow][nextCol] == 0 && !visited[nextRow][nextCol]) {
			visited[nextRow][nextCol] = true;
			danger++;
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	N = board.size();
	M = board[0].size();

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				check(board, i, j);
			}
		}
	}

	answer = N * M - danger;

	return answer;
}