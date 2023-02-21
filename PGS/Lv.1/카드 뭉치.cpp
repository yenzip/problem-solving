#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";

	int i = 0, j = 0;

	for (auto s : goal) {
		if (cards1[i] == s) {
			i++;
		}
		else if (cards2[j] == s) {
			j++;
		}
		else {
			answer = "No";
			break;
		}
	}

	return answer;
}