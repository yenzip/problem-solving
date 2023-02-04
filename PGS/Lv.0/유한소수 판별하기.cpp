#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int solution(int a, int b) {
	if (a % b == 0) {	//정수
		return 1;
	}

	int num = a / gcd(a, b);	// 분자
	int den = b / gcd(a, b);	// 분모

	while (den % 5 == 0) {
		den /= 5;
	}

	while (den % 2 == 0) {
		den /= 2;
	}

	return den == 1 ? 1 : 2;
}