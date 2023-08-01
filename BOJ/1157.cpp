#include <bits/stdc++.h>
using namespace std;

string word;
int A[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> word;

	for (auto c : word) {
		if (islower(c)) {
			c = toupper(c);
		}
		A[c - 'A']++;
	}

	char answer;
	int maxVal = 0;
	int maxCnt = 0;

	for (int i = 0; i < 26; i++) {
		if (!A[i]) {
			continue;
		}

		if (maxVal < A[i]) {
			answer = char('A' + i);
			maxVal = A[i];
			maxCnt = 1;
		}
		else if(maxVal == A[i]) {	// 가장 많이 사용된 알파벳이 여러 개 존재하는 경우
			maxCnt++;
		}
	}

	if (maxCnt > 1) {
		cout << '?';
	}
	else {
		cout << answer;
	}

	return 0;
}