#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
	if (A == B) {
		return 0;
	}

	int cnt = 0;
	string tmp = "";
	for (int i = 0; i < A.size() - 1; i++) {
		tmp += A.back();
		for (int j = 0; j < A.size() - 1; j++) {
			tmp += A[j];
		}
		cnt++;
		if (tmp == B) {
			return cnt;
		}
		A = tmp;
		tmp = "";
	}

	return -1;
}