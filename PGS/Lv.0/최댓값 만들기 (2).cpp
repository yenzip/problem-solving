#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {

	int n = numbers.size();

	sort(numbers.begin(), numbers.end());

	return max(numbers[0] * numbers[1], numbers[n - 1] * numbers[n - 2]);
}