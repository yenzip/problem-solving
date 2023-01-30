#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
	int answer = -1;
	string snum = to_string(num);
	char ck = k + '0';

	for (int i = 0; i < snum.size(); i++) {
		if (snum[i] == ck) {
			answer = i + 1;
			break;
		}
	}
	
	return answer;
}