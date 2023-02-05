#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
	vector<int> answer;

	sort(numlist.rbegin(), numlist.rend());	// ��������

	vector<pair<int, int>> v;	// { ��, �ε��� }

	for (int i = 0; i < numlist.size(); i++) {
		v.push_back({ abs(n - numlist[i]), i });
	}

	sort(v.begin(), v.end());	// �� ���� ����, ���� ���ٸ� �ε������� ����

	for (auto t : v) {
		answer.push_back(numlist[t.second]);
	}

	return answer;
}