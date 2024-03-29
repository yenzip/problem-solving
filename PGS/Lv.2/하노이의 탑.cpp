#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		answer.push_back({ from, to });
		return;
	}

	hanoi(n - 1, from, to, by);
	answer.push_back({ from, to });
	hanoi(n - 1, by, from, to);
}

vector<vector<int>> solution(int n) {

	hanoi(n, 1, 2, 3);

	return answer;
}