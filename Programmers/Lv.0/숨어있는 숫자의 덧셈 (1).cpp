#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
	int answer = 0;

	for (const auto &v : my_string) {
		if (v >= '0' && v <= '9') {
			answer += v - '0';
		}
	}

	return answer;
}