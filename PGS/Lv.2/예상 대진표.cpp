#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;
	
	while (a != b) {
		answer++;
		a % 2 ? a = a / 2 + 1 : a /= 2;
		b % 2 ? b = b / 2 + 1 : b /= 2;
	}

	return answer;
}