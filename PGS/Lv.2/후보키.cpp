#include <bits/stdc++.h>
using namespace std;

int row, col;
bool visited[8];
set<string> candidate;  // 후보키

void check(vector<vector<string>> relation, string cIdx) {
	map<string, int> m;

	sort(cIdx.begin(), cIdx.end());

	for (int i = 0; i < row; i++) {
		string val = "";
		for (int j = 0; j < cIdx.size(); j++) {
			val += relation[i][cIdx[j] - '0'];
		}
		m[val]++;
	}

	if (m.size() == row) {
		bool isCandidate = true;
		for (auto c : candidate) {
			int idx = 0;
			for (int i = 0; i < cIdx.size(); i++) {
				if (c[idx] == cIdx[i]) {
					idx++;
				}
			}
			if (idx == c.size()) {
				isCandidate = false;
				break;
			}
		}
		if (isCandidate) {
			candidate.insert(cIdx);
		}
	}

}

void dfs(vector<vector<string>> relation, int idx, int cnt, string cIdx) {
	if (idx == cnt) {
		check(relation, cIdx);
		return;
	}

	for (int i = idx; i < col; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(relation, idx + 1, cnt, cIdx + (char)('0' + i));
			visited[i] = false;
		}
	}
}

int solution(vector<vector<string>> relation) {

	row = relation.size();
	col = relation[0].size();

	for (int i = 1; i <= col; i++) { // 후보키 속성의 개수
		dfs(relation, 0, i, "");
	}

	return candidate.size();
}