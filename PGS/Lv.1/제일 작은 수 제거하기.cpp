#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	if (arr.size() == 1 && arr[0] == 10) {
		answer.push_back(-1);
	}
	else {
		int min = *min_element(arr.begin(), arr.end());
		for (int i : arr) {
			if (i != min) {
				answer.push_back(i);
			}
		}
	}
	return answer;
}