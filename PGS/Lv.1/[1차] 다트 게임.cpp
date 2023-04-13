#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

int solution(string dartResult) {
	int answer = 0;

	stringstream ss(dartResult);
	int result[3];
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		int score;
		char bonus;
		char option;

		ss >> score;

		bonus = ss.get();
		option = ss.get();

		if (option != '*' && option != '#') {
			ss.unget();
		}

		if (bonus == 'S') {
			result[idx] = score;
		}
		else if (bonus == 'D') {
			result[idx] = pow(score, 2);
		}
		else if (bonus == 'T') {
			result[idx] = pow(score, 3);
		}

		if (option == '*') {
			result[idx] *= 2;
			if (idx - 1 >= 0) {
				result[idx - 1] *= 2;
			}
		}
		else if (option == '#') {
			result[idx] *= (-1);
		}

		idx++;
	}

	answer = accumulate(result, result + 3, 0);

	return answer;
}