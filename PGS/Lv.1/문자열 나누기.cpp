#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	char x;
	int x_cnt;
	int not_x_cnt;
	bool isX = true;
	for (int i = 0; i < s.size(); i++) {
		if (isX) {
			x = s[i];
			x_cnt = 1;
			not_x_cnt = 0;
			isX = false;
		}
		else if (s[i] != x) {
			not_x_cnt++;
		}
		else if (s[i] == x) {
			x_cnt++;
		}

		if (x_cnt == not_x_cnt) {
			answer++;
			isX = true;
		}
	}

	if (x_cnt != not_x_cnt) {
		answer++;
	}

	return answer;
}