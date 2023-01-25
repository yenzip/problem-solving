#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int k) {
	int answer = 0;

	for (int i = 1; i < k; i++) {
		answer = (answer + 2) % numbers.size();
	}

	return numbers[answer];
}