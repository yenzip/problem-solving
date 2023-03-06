#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>

using namespace std;

bool isPrime(long long n) {
	if (n < 2) {
		return false;
	}

	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int solution(int n, int k) {
	int answer = 0;

	string s;
	if (k == 10) {
		s = to_string(n);
	}
	else {
		while (n) {
			s += to_string(n % k);
			n /= k;
		}
		reverse(s.begin(), s.end());
	}

	s = regex_replace(s, regex("[0]+"), " ");

	stringstream ss(s);
	long long num;
	while (ss >> num) {
		if (isPrime(num)) {
			answer++;
		}
	}

	return answer;
}