#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;

	set<int> s;
	int n = elements.size();
	for (int i = 1; i < n; i++) {	// 1 ~ (n-1) 개 연속 합
		vector<int> v(elements.begin(), elements.end());
		for (int j = 0; j < i - 1; j++) {
			v.push_back(elements[j]);
		}

		for (int j = 0; j < n; j++) {
			s.insert(accumulate(v.begin() + j, v.begin() + j + i, 0));
		}
	}

	s.insert(accumulate(elements.begin(), elements.end(), 0));	// n개 연속 합

	answer = s.size();

	return answer;
}