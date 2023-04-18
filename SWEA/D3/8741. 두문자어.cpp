#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	cin.ignore();	// 버퍼 비워주기
	for (int t = 1; t <= T; t++) {
		getline(cin, s);

		string answer;
		stringstream ss(s);
		string word1, word2, word3;
		ss >> word1 >> word2 >> word3;

		answer += toupper(word1[0]);
		answer += toupper(word2[0]);
		answer += toupper(word3[0]);
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}