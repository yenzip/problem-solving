#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	map<string, int> m;
	for (int i = 0; i < want.size(); i++) {
		m[want[i]] = number[i];
	}

	for (int i = 0; i < discount.size() - 9; i++) {
		int j = i;
		map<string, int> tmp(m.begin(), m.end());
		while (j < i + 10 && tmp[discount[j]] > 0 && tmp[discount[j]]--) {
			j++;
		}
		if (j - i == 10) {
			answer++;
		}
	}

	return answer;
}