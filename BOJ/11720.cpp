#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string numbers;

	cin >> N >> numbers;

	int answer = 0;
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i] - '0';
	}

	cout << answer;

	return 0;
}