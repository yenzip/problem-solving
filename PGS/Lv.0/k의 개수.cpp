#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
	int answer = 0;

	while (i <= j) {
		if (to_string(i).find((k + '0')) != string::npos) {
			string s = to_string(i);
			answer += count(s.begin(), s.end(), (k + '0'));
		}
		i++;
	}

	return answer;
}