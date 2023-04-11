#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string result;
		for (int j = n - 1; j >= 0; j--) {
			int a = arr1[i] / (1 << j);
			if (a == 1) {
				arr1[i] -= (1 << j);
			}

			int b = arr2[i] / (1 << j);
			if (b == 1) {
				arr2[i] -= (1 << j);
			}

			a == 1 || b == 1 ? result += '#' : result += ' ';
		}
		answer.push_back(result);
	}

	return answer;
}