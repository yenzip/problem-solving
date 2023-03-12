#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (auto num : numbers) {
		if (num % 2 == 0) {
			answer.push_back(num + 1);
		}
		else {
			long long bit = 1;
			while (num & bit == 1) {
				bit *= 2;
			}
			bit /= 2;

			answer.push_back(num + bit);
		}
	}

	return answer;
}