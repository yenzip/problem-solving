#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
	int answer = 0;
	
	// 1. ó�� ���� ����
	stringstream ss(my_string);
	ss >> answer;

	// 2.
	int n;
	char op;
	while (ss >> op >> n) {
		if (op == '+') {
			answer += n;
		}
		else {
			answer -= n;
		}
	}

	return answer;
}