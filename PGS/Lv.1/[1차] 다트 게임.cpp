#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	vector<int> result;
	string tmp = "";
	int num;
	for (auto i : dartResult) {
		if (isdigit(i)) {
			tmp += i;
		}
		else if (isalpha(i)) {
			if (i == 'S') {
				num = stoi(tmp);
			}
			else if (i == 'D') {
				num = pow(stoi(tmp), 2);
			}
			else if (i == 'T') {
				num = pow(stoi(tmp), 3);
			}
			result.push_back(num);
			tmp = "";
		}
		else {
			if (i == '*') {
				result.back() *= 2;
				if (result.size() > 1) {
					result[result.size() - 2] *= 2;
				}

			}
			else if (i == '#') {
				result.back() *= -1;
			}
		}
	}

	answer = accumulate(result.begin(), result.end(), 0);

	return answer;
}