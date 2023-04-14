#include <bits/stdc++.h>

using namespace std;

int answer = 0;
bool visited[8];

void go(vector<vector<int>> &dungeons, int k, int depth) {
	if (depth <= dungeons.size()) {
		answer = max(answer, depth);
	}

	for (int i = 0; i < dungeons.size(); i++) {
		if (!visited[i] && k >= dungeons[i][0]) {
			visited[i] = true;
			go(dungeons, k - dungeons[i][1], depth + 1);
			visited[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	go(dungeons, k, 0);
	return answer;
}