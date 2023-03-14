#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	int n = numbers.size();
	vector<int> answer(n, 0);

	stack<int> s;
	for (int i = 0; i < n; i++) {
		s.push(i);
		while (i < n - 1 && !s.empty() && numbers[s.top()] < numbers[i + 1]) {
			answer[s.top()] = numbers[i + 1];
			s.pop();
		}
	}

	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	return answer;
}