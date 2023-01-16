#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
	int answer = 0;
	int a = common[1] - common[0];
	int b = common[2] - common[1];
	if (a == b) {	// 등차수열
		answer = common.back() + a;
	}
	else {	// 등비수열
		a = common[1] / common[0];
		answer = common.back() * a;
	}
	return answer;
}