#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
	vector<int> answer;

	if (direction == "right") {
		answer.push_back(numbers.back());
		answer.insert(answer.end(), numbers.begin(), numbers.end() - 1);
	}
	else {
		answer.insert(answer.begin(), numbers.begin() + 1, numbers.end());
		answer.push_back(numbers.front());
	}
	return answer;
}