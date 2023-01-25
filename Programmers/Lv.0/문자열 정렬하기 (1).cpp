#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
	vector<int> answer;

	for (const auto &v : my_string) {
		if (v >= '0' && v <= '9') {
			answer.push_back(v - '0');
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}