#include <string>
#include <vector>

using namespace std;

int countOne(int n) {
	int cnt = 0;
	while (n) {
		if (n % 2) {
			cnt++;
		}
		n /= 2;
	}
	return cnt;
}

int solution(int n) {
	int n_1 = countOne(n);

	int answer = n + 1;	// next
	while (countOne(answer++) != n_1);

	return answer;
}