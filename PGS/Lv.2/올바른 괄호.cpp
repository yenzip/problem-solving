#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;	// isVPS
	int size = 0;
	for (auto i : s) {
		if (i == '(') {
			size++;
		}
		else {	// ')'
			if (size == 0) {
				answer = false;
				break;
			}
			size--;
		}
	}

	return  answer && size == 0 ? true : false;
}