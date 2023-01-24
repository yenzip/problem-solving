#include <bits/stdc++.h>

using namespace std;

int main() {
	string S;
	int size = 0;	// 스택의 크기
	int answer = 0;

	cin >> S;

	int i = 0;
	while (i < S.size()) {
		if (S[i] == '(' && S[i + 1] == ')') {	// 레이저
			answer += size;
			i++;
		}
		else if (S[i] == '(') {
			size++;
		}
		else if (S[i] == ')') {
			size--;
			answer += 1;	// 막대기의 끝
		}
		i++;
	}

	cout << answer;

	return 0;
}