#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
	vector<int> answer;
	int denom = denom1 * denom2;
	int numer = numer1 * denom2 + numer2 * denom1;
	for (int i = min(denom, numer); i > 1; i--) {
		if (denom % i == 0 && numer % i == 0) {
			denom /= i;
			numer /= i;
		}
	}
	answer.push_back(numer);
	answer.push_back(denom);
	return answer;
}