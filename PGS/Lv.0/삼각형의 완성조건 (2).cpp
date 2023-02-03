#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
	int answer = 0;

	if (sides[0] > sides[1]) {
		swap(sides[0], sides[1]);
	}

	// 1. sides에서 가장 큰 변이 가장 긴 경우
	for (int i = (sides[1] - sides[0]) + 1; i <= sides[1]; i++) {
		answer++;
	}

	// 2. 나머지 한 변이 가장 긴 경우
	for (int i = sides[1] + 1; i < (sides[0] + sides[1]); i++) {
		answer++;
	}

	return answer;
}