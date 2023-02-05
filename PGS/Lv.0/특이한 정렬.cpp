#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
	vector<int> answer;

	sort(numlist.rbegin(), numlist.rend());	// 내림차순

	vector<pair<int, int>> v;	// { 차, 인덱스 }

	for (int i = 0; i < numlist.size(); i++) {
		v.push_back({ abs(n - numlist[i]), i });
	}

	sort(v.begin(), v.end());	// 차 별로 정렬, 차가 같다면 인덱스별로 정렬

	for (auto t : v) {
		answer.push_back(numlist[t.second]);
	}

	return answer;
}