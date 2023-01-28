#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
	long long answer = 0;
	string sNumber;

	int i = 0;
	while (i < numbers.size()) {
		if (numbers[i] == 'z') {
			sNumber += '0';
			i += 4;
		}
		else if (numbers[i] == 'o') {
			sNumber += '1';
			i += 3;
		}
		else if (numbers[i] == 't') {
			if (numbers[i + 1] == 'w') {
				sNumber += '2';
				i += 3;
			}
			else {
				sNumber += '3';
				i += 5;
			}
		}
		else if (numbers[i] == 'f') {
			if (numbers[i + 1] == 'o') {
				sNumber += '4';
			}
			else {
				sNumber += '5';
			}
			i += 4;
		}
		else if (numbers[i] == 's') {
			if (numbers[i + 1] == 'i') {
				sNumber += '6';
				i += 3;
			}
			else {
				sNumber += '7';
				i += 5;
			}
		}
		else if (numbers[i] == 'e') {
			sNumber += '8';
			i += 5;
		}
		else if (numbers[i] == 'n') {
			sNumber += '9';
			i += 4;
		}
	}

	answer = stoll(sNumber);

	return answer;
}