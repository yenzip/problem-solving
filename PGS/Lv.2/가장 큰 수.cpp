#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b) {
	return stoi(a + b) > stoi(b + a);
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> v;
	for (auto num : numbers) {
		v.push_back(to_string(num));
	}

	int zero = count(numbers.begin(), numbers.end(), 0);
	if (zero == numbers.size()) {
		answer = '0';
	}
	else {
		sort(v.begin(), v.end(), comp);

		for (auto i : v) {
			answer += i;
		}
	}

	return answer;
}