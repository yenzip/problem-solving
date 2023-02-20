#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
	vector<int> answer;

	for (auto i : my_string) {
		if (isdigit(i)) {
			answer.push_back(i - '0');
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}