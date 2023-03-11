#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;

	int cur = 0;
	for (auto s : section) {
		if (cur <= s) {
			answer++;
			cur = s + m;
		}
	}

	return answer;
}