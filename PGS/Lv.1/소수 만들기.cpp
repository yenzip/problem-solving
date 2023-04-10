#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;

	vector<int> idx(nums.size() - 3, 0);
	for (int i = 0; i < 3; i++) {
		idx.push_back(1);
	}

	do {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (idx[i]) {
				sum += nums[i];
			}
		}
		if (check(sum)) {
			answer++;
		}
	} while (next_permutation(idx.begin(), idx.end()));

	return answer;
}