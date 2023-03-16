#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;

	long long sum1 = 0;
	queue<long long> q1;
	for (auto i : queue1) {
		q1.push(i);
		sum1 += i;
	}

	long long sum2 = 0;
	queue<long long> q2;
	for (auto i : queue2) {
		q2.push(i);
		sum2 += i;
	}

	if ((sum1 + sum2) % 2 == 1) {
		return -1;
	}

	while (sum1 != sum2) {
		if (answer > queue1.size() * 4) {
			answer = -1;
			break;
		}

		if (sum1 > sum2) {
			q2.push(q1.front());
			sum2 += q1.front();
			sum1 -= q1.front();
			q1.pop();
		}
		else if (sum1 < sum2) {
			q1.push(q2.front());
			sum1 += q2.front();
			sum2 -= q2.front();
			q2.pop();
		}
		answer++;
	}

	return answer;
}