#include <bits/stdc++.h>
using namespace std;

int S, P;
string DNA;
int checkArr[4];	// { A, C, G, T }
int pwdArr[4];		// { A, C, G, T }

void add(char c) {
	switch (c) {
	case 'A':
		pwdArr[0]++;
		break;
	case 'C':
		pwdArr[1]++;
		break;
	case 'G':
		pwdArr[2]++;
		break;
	case 'T':
		pwdArr[3]++;
	}
}

void remove(char c) {
	switch (c) {
	case 'A':
		pwdArr[0]--;
		break;
	case 'C':
		pwdArr[1]--;
		break;
	case 'G':
		pwdArr[2]--;
		break;
	case 'T':
		pwdArr[3]--;
	}
}

bool validation() {
	if (checkArr[0] > pwdArr[0]) return false;
	else if (checkArr[1] > pwdArr[1]) return false;
	else if (checkArr[2] > pwdArr[2]) return false;
	else if (checkArr[3] > pwdArr[3]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> P;
	cin >> DNA;
	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];
	}

	for (int i = 0; i < P; i++) {
		add(DNA[i]);
	}

	int answer = 0;
	for (int end = P; end <= S; end++) {
		if (validation()) answer++;
		int start = end - P;
		add(DNA[end]);
		remove(DNA[start]);
	}

	cout << answer;

	return 0;
}