#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	vector<int> w, h;
	for (int i = 0; i < sizes.size(); i++) {
		sort(sizes[i].rbegin(), sizes[i].rend());
		w.push_back(sizes[i][0]);
		h.push_back(sizes[i][1]);
	}

	int w_max = *max_element(w.begin(), w.end());
	int h_max = *max_element(h.begin(), h.end());

	answer = w_max * h_max;

	return answer;
}