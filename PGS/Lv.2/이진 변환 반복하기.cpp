#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2, 0);	// (idx, rm)

	while (s != "1") {
		answer[0]++;

		// 1.
		answer[1] += count(s.begin(), s.end(), '0');
		s.erase(remove(s.begin(), s.end(), '0'), s.end());

		// 2.
		int c = s.size();
		s.clear();
		while (c) {
			s.push_back(c % 2 + '0');
			c /= 2;
		}
		reverse(s.begin(), s.end());
	}


	return answer;
}