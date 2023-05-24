#include <bits/stdc++.h>
using namespace std;

int N, M;
set<string> S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		S.insert(str);
	}

	int answer = 0;
	for (int i = 0; i < M; i++) {
		string search;
		cin >> search;
		if (S.find(search) != S.end()) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}