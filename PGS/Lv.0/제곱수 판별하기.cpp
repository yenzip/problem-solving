#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
	int i = sqrt(n);
	if (i * i == n) {
		return 1;
	}
	return 2;
}