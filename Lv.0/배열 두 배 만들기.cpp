#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers);
	for (int i = 0; i < numbers.size(); i++) {
		answer[i] = answer[i] * 2;
	}
	return answer;
}