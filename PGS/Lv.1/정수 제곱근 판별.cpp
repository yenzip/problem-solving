#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long x = sqrt(n);
	return x * x == n ? pow(x + 1, 2) : -1;
}