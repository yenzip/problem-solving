#include <bits/stdc++.h>
using namespace std;

string S, T;
bool isPossible;

void dfs(string t) {
	if (t.size() == S.size()) {
		if (t == S) {
			isPossible = true;
		}
		return;
	}

	if (t.back() == 'A') {
		dfs(t.substr(0, t.size() - 1));
	}
	if(t.front() == 'B') {
		string tmp = t.substr(1);
		reverse(tmp.begin(), tmp.end());
		dfs(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> T;

	dfs(T);

	cout << isPossible;

	return 0;
}