#include <string>
#include <vector>
#include <set>
#include <regex>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<string> tmp(n);
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			tmp[j].push_back(board[i][j]);
		}
	}


	while (1) {
		board.assign(tmp.begin(), tmp.end());

		set<pair<int, int>> s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (i + 1 < n && j + 1 < board[i].size() && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
					s.insert({ i, j });		s.insert({ i, j + 1 });
					s.insert({ i + 1, j });	s.insert({ i + 1, j + 1 });
					tmp[i][j] = '*';		tmp[i][j + 1] = '*';
					tmp[i + 1][j] = '*';	tmp[i + 1][j + 1] = '*';
				}
			}
		}

		if (s.empty()) {
			break;
		}

		answer += s.size();
		for (auto& i : tmp) {
			i = regex_replace(i, regex("[*]+"), "");
		}
	}

	return answer;
}