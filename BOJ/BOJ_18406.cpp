#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;

	int s1 = 0, s2 = 0;
	for (int i = 0; i < N.size(); i++) {
		if (i < N.size() / 2) {
			s1 += N[i] - '0';
		}
		else {
			s2 += N[i] - '0';
		}
	}
	
	s1 == s2 ? cout << "LUCKY" : cout << "READY";

	return 0;
}