#include <bits/stdc++.h>
using namespace std;

int N;
string S;

string getPwd() {
	string pwd;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == S[i + 1]) {
			i++;
		}
		else {
			pwd += S[i];
		}
	}
	return pwd;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 1; t <= 2; t++) {
		cin >> N >> S;
		while (1) {
			int size = S.size();
			S = getPwd();
			if (S.size() == size) {
				break;
			}
		}
		cout << '#' << t << ' ' << S << '\n';
	}

	return 0;
}