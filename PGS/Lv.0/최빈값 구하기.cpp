#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
	int answer = 0;
	int fValue, fCnt = 0, flag = 0;
	for (int i = 0, n; i < array.size(); i++) {
		n = count(array.begin(), array.end(), array[i]);
		if (fCnt < n) {
			if (flag == 1) {
				flag = 0;
			}
			fValue = array[i];
			fCnt = n;
		}
		else if (fCnt == n) {
			if (array[i] == fValue) {
				continue;
			}
			flag = 1;
		}
	}

	if (flag == 1)
		answer = -1;
	else
		answer = fCnt;
	return answer;
}