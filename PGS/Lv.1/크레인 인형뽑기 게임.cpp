#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	for (auto m : moves) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][m - 1] != 0) {
				if (!s.empty() && s.top() == board[i][m - 1]) {
					answer += 2;
					s.pop();
				}
				else {
					s.push(board[i][m - 1]);
				}
				board[i][m - 1] = 0;
				break;
			}
		}
	}

	return answer;
}