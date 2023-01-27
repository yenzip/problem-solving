#include <string>
#include <vector>

using namespace std;

int solution(int order) {
	int answer = 0;
	string num = to_string(order);
	for (char n : num) {
		if (n == '3' || n == '6' || n == '9') {
			answer++;
		}
	}
	return answer;
}