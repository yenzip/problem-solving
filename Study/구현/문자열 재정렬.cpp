#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	string str, answer;
	int num = 0;
	for (auto c : S) {
		if (isupper(c)) {
			str += c;
		}
		else if (isdigit(c)) {
			num += c - '0';
		}
	}

	sort(str.begin(), str.end());

	answer += str + to_string(num);

	cout << answer;

	return 0;
}