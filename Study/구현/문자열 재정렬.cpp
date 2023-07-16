#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	string answer;
	int number = 0;

	for (auto c : S) {
		if (isdigit(c)) {
			number += c - '0';
		}
		else {
			answer += c;
		}
	}

	sort(answer.begin(), answer.end());

	if (number != 0) {
		answer += to_string(number);
	}

	cout << answer;

	return 0;
}