#include <string>
#include <vector>

using namespace std;

bool composite(int n) {
	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {
		if (i * i == n) {
			cnt++;
		}
		else if (n % i == 0) {
			cnt += 2;
		}
	}

	return cnt >= 3 ? true : false;
}

int solution(int n) {
	int answer = 0;

	for (int i = 2; i <= n; i++) {
		if (composite(i)) {
			answer++;
		}
 	}

	return answer;
}