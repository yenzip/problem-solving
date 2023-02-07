#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
	int answer = 0;

	string num = to_string(n);
	for (auto i : num) {
		answer += i - '0';
	}

	return answer;
}