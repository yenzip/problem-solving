#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(vector<int> &numbers, int target, int start, int num, int depth) {
	if (depth == numbers.size()) {
		if (num == target) {
			answer++;
		}
		return;
	}
	dfs(numbers, target, start + 1, num + numbers[start], depth + 1);
	dfs(numbers, target, start + 1, num - numbers[start], depth + 1);
}

int solution(vector<int> numbers, int target) {

	dfs(numbers, target, 0, 0, 0);
	return answer;
}