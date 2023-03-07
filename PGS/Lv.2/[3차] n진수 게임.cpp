#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";

	string c = "0123456789ABCDEF";
	string s = "0";
	int num = 1;

	while (s.size() <= t * m) {
		int tmp = num;
		string stmp = "";

		while (tmp) {
			stmp += c[tmp % n];
			tmp /= n;
		}

		reverse(stmp.begin(), stmp.end());
		s += stmp;
		num++;
	}

	for (int i = p - 1, k = 0; k < t; i += m, k++) {
		answer += s[i];
	}

	return answer;
}