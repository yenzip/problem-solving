#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 9 * 10 / 2;
	for (int num : numbers) {
		answer -= num;
	}
	return answer;
}