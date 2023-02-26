#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int length, height;
	for (int i = 1; i * i <= yellow; i++) {
		if (yellow % i == 0) {
			height = i;
			length = yellow / i;
			if ((length + 2) * (height + 2) == (brown + yellow)) {
				answer.push_back(length + 2);
				answer.push_back(height + 2);
				break;
			}
		}
	}

	return answer;
}