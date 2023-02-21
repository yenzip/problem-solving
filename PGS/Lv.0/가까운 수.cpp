#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> array, int n) {

	sort(array.begin(), array.end());

	int idx = 0;
	int closet = abs(array[0] - n);
	for (int i = 1; i < array.size(); i++) {
		if (closet > abs(array[i] - n)) {
			idx = i;
			closet = abs(array[i] - n);
		}
	}

	return array[idx];
}