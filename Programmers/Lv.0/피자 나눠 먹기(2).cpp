#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int solution(int n) {
	int answer = n / gcd(n, 6);
	return answer;
}