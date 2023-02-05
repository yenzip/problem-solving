#include <string>
#include <vector>

using namespace std;

int a[201] = { 0, };

int solution(vector<vector<int>> lines) {
	int answer = 0;

	for (auto line : lines) {
		for (int i = line[0]; i < line[1]; i++) {
			a[i + 100]++;
		}
	}

	for (int i = 0; i <= 201; i++) {
		if (a[i] >= 2) {
			answer++;
		}
	}

	return answer;
}