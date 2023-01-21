#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
	vector<int> answer(emergency.size(), 0);

	for (int i = 0; i < emergency.size(); i++) {
		int num = emergency[i];
		for (int j = 0; j < emergency.size(); j++) {
			if (num <= emergency[j]) {
				answer[i]++;
			}
		}
	}

	return answer;
}