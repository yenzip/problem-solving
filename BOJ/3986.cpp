#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;

	cin >> N;

	while (N--) {
		cin >> S;

		stack<char> stk;

		for (char c : S) {
			if (!stk.empty() && stk.top() == c) {
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}

		if (stk.size() == 0) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}