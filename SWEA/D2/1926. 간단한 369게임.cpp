#include <bits/stdc++.h>
using namespace std;

int N;

string check(int num) {
	string s = to_string(num);
	int clap = 0;
	for (auto c : s) {
		if (c == '3' || c == '6' || c == '9') {
			clap++;
		}
	}
	return clap ? string(clap, '-') : s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << check(i) << ' ';
	}
	
	return 0;
}