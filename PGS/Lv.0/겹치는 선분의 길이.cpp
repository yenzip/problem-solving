#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
	int answer = 0;

	sort(lines.begin(), lines.end());

	vector<pair<int, int>> overlap;

	if (lines[0][1] > lines[1][0]) {
		overlap.push_back({ max(lines[0][0], lines[1][0]), min(lines[0][1], lines[1][1]) });
	}

	if (lines[0][1] > lines[2][0]) {
		overlap.push_back({ max(lines[0][0], lines[2][0]), min(lines[0][1], lines[2][1]) });
	}

	if (lines[1][1] > lines[2][0]) {
		overlap.push_back({ max(lines[1][0], lines[2][0]), min(lines[1][1], lines[2][1]) });
	}
	


	return answer;
}