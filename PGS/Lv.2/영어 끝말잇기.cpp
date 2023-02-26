#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);

	vector<string> v;
	v.push_back(words[0]);

	int turn = 1;
	for (int i = 1; i < words.size(); i++) {
		if (i % n == 0) {
			turn++;
		}

		if ((words[i - 1].back() != words[i].front()) || (find(v.begin(), v.end(), words[i]) != v.end())) {
			answer[0] = i % n + 1;
			answer[1] = turn;
			break;
		}
		else {
			v.push_back(words[i]);
		}
	}

	return answer;
}