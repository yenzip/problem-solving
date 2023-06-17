#include <bits/stdc++.h>
using namespace std;

bool visited[7];
set<int> s;

bool isPrime(int x) {
	if (x < 2) {
		return false;
	}

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

void makeNumber(string num, string numbers) {
	if (!num.empty() && isPrime(stoi(num))) {
		s.insert(stoi(num));
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			makeNumber(num + numbers[i], numbers);
			visited[i] = false;
		}
	}
}

int solution(string numbers) {

	makeNumber("", numbers);

	return s.size();
}