#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char ch[3] = { '4', '1', '2' };

string solution(int n) {
	string answer = "";

	while (n) {
		answer += ch[n % 3];

		if (n % 3 == 0) {
			n /= 3;
			n -= 1;
		}
		else {
			n /= 3;
		}
	}

	reverse(answer.begin(), answer.end());

	return answer;
}