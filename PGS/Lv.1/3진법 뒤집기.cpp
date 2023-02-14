#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
	int answer = 0;
	string s = "";
	while (n) {
		s += n % 3 + '0';
		n /= 3;
	}
	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {
		answer += (s[i] - '0') * pow(3, i);
	}

	return answer;
}