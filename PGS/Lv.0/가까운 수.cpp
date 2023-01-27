#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
	int answer = 0;
	int closet = 100, pos;

	for (int i = 0; i < array.size(); i++) {
		int num = abs(array[i] - n);
		if (closet > num) {
			closet = num;
			pos = i;
		}
		else if (closet == num && array[pos] > array[i]) {
			pos = i;
		}
	}

	answer = array[pos];
	return answer;
}