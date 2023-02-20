#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
	string answer = "";

	sort(X.rbegin(), X.rend());
	sort(Y.rbegin(), Y.rend());

	int i = 0, j = 0;
	while (i < X.size() && j < Y.size()) {
		if (X[i] == Y[j]) {
			answer += X[i];
			i++;
			j++;
		}
		else if (X[i] < Y[j]) {
			j++;
		}
		else {
			i++;
		}
	}

	if (answer.empty()) {
		answer = "-1";
	}
	else if (answer[0] == '0') {
		answer = "0";
	}

	return answer;
}