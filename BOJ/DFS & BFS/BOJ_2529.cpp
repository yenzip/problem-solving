#include <bits/stdc++.h>
using namespace std;

int k;
char sign[9];
bool visited[10];
vector<string> result;

bool check(string s) {
	for (int i = 0; i < k; i++) {
		if (sign[i] == '<') {
			if (s[i] > s[i + 1]) {
				return false;
			}
		}
		else if (sign[i] == '>') {
			if (s[i] < s[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

void dfs(string s, int depth) {
	if (depth == k + 1) {
		if (check(s)) {
			result.push_back(s);
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(s + to_string(i), depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}
	
	dfs("", 0);

	auto answer = minmax_element(result.begin(), result.end());
	cout << *answer.second << '\n';
	cout << *answer.first << '\n';

	return 0;
}