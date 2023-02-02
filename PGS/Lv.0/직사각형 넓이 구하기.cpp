#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
	int length, height;

	sort(dots.begin(), dots.end());

	height = abs(dots[3][1] - dots[0][1]);
	length = abs(dots[3][0] - dots[0][0]);

	return length * height;
}