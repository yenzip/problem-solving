#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
	vector<int> answer;

	if (total%num == 0) {
		int mid = total / num;

		for (int i = (num - 1) / 2; i > 0; i--) {
			answer.push_back(mid - i);
		}
		answer.push_back(mid);
		for (int i = 1; i <= (num - 1) / 2; i++) {
			answer.push_back(mid + i);
		}
	}
	else {
		int mid1, mid2;
		mid1 = total / num;
		mid2 = mid1 + 1;

		for (int i = (num - 2) / 2; i > 0; i--) {
			answer.push_back(mid1 - i);
		}
		answer.push_back(mid1);
		answer.push_back(mid2);
		for (int i = 1; i <= (num - 2) / 2; i++) {
			answer.push_back(mid2 + i);
		}
	}
	return answer;
}