#include <string>
#include <vector>
#include <numeric>

using namespace std;

int sum(int n) {
	return n * (n + 1) / 2;
}

int solution(int n) {
	int answer = 1;

	for (int s = 1; s <= n; s++) {	// start
		for (int e = s + 1; e <= n; e++) {	// end
			if ((sum(e) - sum(e - s - 1)) == n) {
				answer++;
			}
			else if ((sum(e) - sum(e - s - 1)) > n) {
				break;
			}
		}
	}

	return answer;
}