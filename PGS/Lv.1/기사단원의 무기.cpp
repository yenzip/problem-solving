#include <string>
#include <vector>

using namespace std;

int divisors(int n) {
	int i;
	int cnt = 0;
	for (i = 1; i *i < n; i++) {
		if (n % i == 0) {
			cnt++;
		}
	}

	return (i * i == n) ? cnt * 2 + 1 : cnt * 2;
}

int solution(int number, int limit, int power) {
	int answer = 0;
	
	for (int i = 1; i <= number; i++) {
		int cnt = divisors(i);
		answer += cnt > limit ? power : cnt;
	}

	return answer;
}