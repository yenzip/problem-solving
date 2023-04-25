#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	int w = 0, h = 0;
	for (auto size : sizes) {
		sort(size.begin(), size.end());
		w = max(w, size[0]);
		h = max(h, size[1]);
	}

	answer = w * h;

	return answer;
}