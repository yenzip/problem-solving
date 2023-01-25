#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
	vector<int> answer;
	answer.resize(numbers.size());

	if (direction == "right") {
		for (int i = 0; i < numbers.size(); i++) {
			answer[(i + 1) % numbers.size()] = numbers[i];
		}
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			answer[i] = numbers[(i + 1) % numbers.size()];
		}
	}
	return answer;
}