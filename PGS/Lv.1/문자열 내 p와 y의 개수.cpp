#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	int p = 0, y = 0;
	for (auto i : s) {
		if (i == 'P' || i == 'p') {
			p++;
		}
		if (i == 'Y' || i == 'y') {
			y++;
		}
	}

	return p == y;
}