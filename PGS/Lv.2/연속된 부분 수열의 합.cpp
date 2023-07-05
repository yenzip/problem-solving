#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;
	int n = sequence.size();

	int start = 0, end = 0; // 구간의 시작과 끝 인덱스
	int sum = sequence[0];
	int len = n + 1;

	while (start <= end && end <= n) {
		if (sum <= k) {
			if (sum == k && len > (end - start + 1)) {
				len = end - start + 1;
				answer = { start, end };
			}
			end++;
			sum += sequence[end];
		}
		else {
			sum -= sequence[start];
			start++;
		}
	}

	return answer;
}