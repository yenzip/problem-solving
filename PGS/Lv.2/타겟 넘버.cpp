#include <string>
#include <vector>

using namespace std;


int solution(vector<int> numbers, int target) {
	int answer = 0;

	vector<vector<int>> v;
	v[0].push_back(numbers[0]);
	v[0].push_back(-numbers[0]);

	for (int i = 1; i < numbers.size(); i++) {
		for (int next : v[i - 1]) {
			v[i].push_back(next + numbers[i]);
			v[i].push_back(next - numbers[i]);
		}
	}

	for (auto i : v[numbers.size() - 1]) {
		if (i == target) {
			answer++;
		}
	}

	return answer;
}