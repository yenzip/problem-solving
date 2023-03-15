#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;

	map<int, int> m1, m2;
	for (auto t : topping) {
		m1[t]++;
	}

	while (!topping.empty()) {
		int t = topping.back();
		m2[t]++;	
		topping.pop_back();
		m1[t]--;

		if (m1[t] == 0) {
			m1.erase(t);
		}

		if (m1.size() == m2.size()) {
			answer++;
		}
	}

	return answer;
}