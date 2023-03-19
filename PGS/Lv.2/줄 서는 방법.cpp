#include <string>
#include <vector>

using namespace std;


vector<int> solution(int n, long long k) {
	vector<int> answer;

	long long factorial[21];
	factorial[0] = 1;

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		factorial[i] = factorial[i - 1] * i;
		v.push_back(i);
	}

	k--;
	while (n) {
		int idx = k / factorial[n - 1];
		answer.push_back(v[idx]);
		v.erase(v.begin() + idx);
		k = k % factorial[n - 1];
		n--;
	}
	

	return answer;
}