#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);	// 처리 결과 이메일 받은 횟수

	vector<vector<string>> v;
	vector<int> cnt(id_list.size(), 0);	// 신고 당한 횟수

	v.resize(id_list.size());

	for (auto i : report) {
		stringstream ss(i);
		string a, b;
		ss >> a >> b;

		int a_idx = find(id_list.begin(), id_list.end(), a) - id_list.begin();
		int b_idx = find(id_list.begin(), id_list.end(), b) - id_list.begin();

		if (find(v[a_idx].begin(), v[a_idx].end(), b) == v[a_idx].end()) {	// 동일한 유저의 신고처리는 1회로 제한
			v[a_idx].push_back(b);
			cnt[b_idx]++;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (auto reported : v[i]) {
			int idx = find(id_list.begin(), id_list.end(), reported) - id_list.begin();
			if (cnt[idx] >= k) {
				answer[i]++;
			}
		}
	}

	return answer;
}