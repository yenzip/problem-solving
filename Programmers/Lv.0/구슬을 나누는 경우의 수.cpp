#include <bits/stdc++.h>

using namespace std;

int solution(int balls, int share) {
	int answer = 0;
	__int128 n = 1, m = 1;
	for (int i = 0, j = balls, k = share; i < share; i++, j--, k--) {
		n *= j;
		m *= k;
	}
	answer = n / m;
	return answer;
}