#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string numbers) {
	long long answer = 0;

	vector<string> v = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string num = "";
	string tmp = "";
	for (auto i : numbers) {
		tmp += i;
		if (find(v.begin(), v.end(), tmp) != v.end()) {
			int idx = find(v.begin(), v.end(), tmp) - v.begin();
			num += to_string(idx);
			tmp = "";
		}
	}

	answer = stoll(num);

	return answer;
}