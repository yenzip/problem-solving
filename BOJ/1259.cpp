#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string N;
	
	while(1) {
		cin >> N;

		if (N == "0") {
			break;
		}

		string buf = N;
		reverse(buf.begin(), buf.end());	// O(n)

		if (buf == N) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	} 

	return 0;
}