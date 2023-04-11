#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string answer = "+++++";
	for (int i = 0; i < 5; i++) {
		answer[i] = '#';
		cout << answer << '\n';
		answer[i] = '+';
	}

	return 0;
}