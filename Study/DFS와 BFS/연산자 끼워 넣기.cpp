#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> num;
int add, sub, mul, divi;
int maxValue = -1e9;
int minValue = 1e9;

void dfs(int result, int depth) {
	if (depth == N) {
		minValue = min(minValue, result);
		maxValue = max(maxValue, result);
		return;
	}

	if (add > 0) {
		add -= 1;
		dfs(result + num[depth], depth + 1);
		add += 1;
	}
	if (sub > 0) {
		sub -= 1;
		dfs(result - num[depth], depth + 1);
		sub += 1;
	}
	if (mul > 0) {
		mul -= 1;
		dfs(result * num[depth], depth + 1);
		mul += 1;
	}
	if (divi > 0) {
		divi -= 1;
		dfs(result / num[depth], depth + 1);
		divi += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> add >> sub >> mul >> divi;

	dfs(num[0], 1);

	cout << maxValue << "\n" << minValue << "\n";

	return 0;
}