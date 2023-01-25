#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	int ind = 2;
	int isPrime;

	while (n > 1) {
		isPrime = 0;
		while (n % ind == 0) {
			n /= ind;
			isPrime = 1;
		}
		if (isPrime) {
			answer.push_back(ind);
		}
		ind++;
	}

	return answer;
}