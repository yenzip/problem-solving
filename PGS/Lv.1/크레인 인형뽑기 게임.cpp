#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<vector<int>> v(board.size());
	for (int j = 0; j < board.size(); j++) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][j]) {
				v[j].push_back(board[i][j]);
			}
		}
		reverse(v[j].begin(), v[j].end());
	}

	stack<int> s;
	for (auto i : moves) {
		if (v[i - 1].empty()) {
			continue;
		}

		if (!s.empty() && s.top() == v[i - 1].back()) {
			s.pop();
			answer += 2;
		}
		else {
			s.push(v[i - 1].back());
		}

		v[i - 1].pop_back();
	}

	return answer;
}