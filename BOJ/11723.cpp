#include <bits/stdc++.h>
using namespace std;

int M, x;
string cmd;
bool S[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "add") {
			cin >> x;
			S[x] = true;
		}
		if (cmd == "remove") {
			cin >> x;
			S[x] = false;
		}
		if (cmd == "check") {
			cin >> x;
			cout << S[x] << "\n";
		}
		if (cmd == "toggle") {
			cin >> x;
			S[x] = !S[x];
		}
		if (cmd == "all") {
			memset(S, true, sizeof(S));
		}
		if (cmd == "empty") {
			memset(S, false, sizeof(S));
		}
	}

	return 0;
}