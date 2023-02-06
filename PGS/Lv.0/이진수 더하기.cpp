#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
	string answer = "";

	reverse(bin1.begin(), bin1.end());
	reverse(bin2.begin(), bin2.end());

	int n1 = 0, n2 = 0, n;
	int m = 1;

	for (auto s : bin1) {
		n1 += m * (s - '0');
		m *= 2;
	}

	m = 1;

	for (auto s : bin2) {
		n2 += m * (s - '0');
		m *= 2;
	}

	n = n1 + n2;
	m = 1;
	while (n > 2) {
		answer += to_string(n % 2);
		n /= 2;
	}
	answer += to_string(n);

	reverse(answer.begin(), answer.end());

	return answer;
}