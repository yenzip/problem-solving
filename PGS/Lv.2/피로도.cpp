#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool visited[8];
int total = 0;

void dfs(vector<vector<int>> &dungeons, int k, int depth) {
	for (int i = 0; i < N; i++) {
		if (!visited[i] && k >= dungeons[i][0]) {
			visited[i] = true;
			dfs(dungeons, k - dungeons[i][1], depth + 1);
			visited[i] = false;
		}
	}

	total = max(total, depth);
	return;
}

int solution(int k, vector<vector<int>> dungeons) {
	
	N = dungeons.size();

	dfs(dungeons, k, 0);

	return total;
}