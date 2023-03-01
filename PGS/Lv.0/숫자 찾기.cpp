#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int num, int k) {
	int answer = -1;

	string s = to_string(num);

	if (s.find('0' + k) != string::npos) {
		answer = find(s.begin(), s.end(), '0' + k) - s.begin() + 1;
	}

	return answer;
}