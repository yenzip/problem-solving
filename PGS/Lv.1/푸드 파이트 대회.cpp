#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
	string answer = "";

	string tmp = "";
	for (int i = 1; i < food.size(); i++) {
		tmp += string(food[i] / 2, i + '0');
	}
	answer += tmp + '0';

	reverse(tmp.begin(), tmp.end());
	answer += tmp;

	return answer;
}