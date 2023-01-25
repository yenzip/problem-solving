#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;
	int max, max2;

	max = *max_element(numbers.begin(), numbers.end());
	numbers.erase(remove(numbers.begin(), numbers.end(), max), numbers.end());

	max2 = *max_element(numbers.begin(), numbers.end());

	answer = max * max2;

	return answer;
}