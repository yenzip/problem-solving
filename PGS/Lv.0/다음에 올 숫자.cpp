#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
	int n = common.size();
	if ((common[1] - common[0]) == (common[2] - common[1])) {
		int d = common[1] - common[0];
		return common.back() + d;
	}
	else {
		int r = common[1] / common[0];
		return common.back() * r;
	}
}