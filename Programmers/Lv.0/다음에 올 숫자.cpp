#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
	int answer = 0;
	int a = common[1] - common[0];
	int b = common[2] - common[1];
	if (a == b) {	// ��������
		answer = common.back() + a;
	}
	else {	// ������
		a = common[1] / common[0];
		answer = common.back() * a;
	}
	return answer;
}