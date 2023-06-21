#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
vector<int> answer;

vector<int> solution(vector<string> keymap, vector<string> targets) {

	for (int i = 0; i < keymap.size(); i++) {
		for (int j = 0; j < keymap[i].size(); j++) {
			if (m.find(keymap[i][j]) == m.end()) {
				m[keymap[i][j]] = j + 1;
			}
			else {
				m[keymap[i][j]] = min(m[keymap[i][j]], j + 1);
			}
		}
	}

	for (int i = 0; i < targets.size(); i++) {
		int press = 0;
		for (int j = 0; j < targets[i].size(); j++) {
			if (m.find(targets[i][j]) == m.end()) {
				press = -1;
				break;
			}
			else {
				press += m[targets[i][j]];
			}
		}
		answer.push_back(press);
	}

	return answer;
}