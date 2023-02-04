#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;

	sort(dots.begin(), dots.end());

	int x1 = dots[0][0];	int y1 = dots[0][1];
	int x2 = dots[1][0];	int y2 = dots[1][1];
	int x3 = dots[2][0];	int y3 = dots[2][1];
	int x4 = dots[3][0];	int y4 = dots[3][1];

	if ((y2 - y1) * (x4 - x3) == (y4 - y3) *(x2 - x1)) {
		return 1;
	}

	if ((y4 - y2) *(x3 - x1) == (y3 - y1) *(x4 - x2)) {
		return 1;
	}

	if ((y4 - y1)*(x3 - x2) == (y3 - y2)*(x4 - x1)) {
		return 1;
	}


	return 0;
}