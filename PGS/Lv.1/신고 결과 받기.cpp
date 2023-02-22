#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);	// ó�� ��� �̸��� ���� Ƚ��

	vector<vector<string>> v;
	vector<int> cnt(id_list.size(), 0);	// �Ű� ���� Ƚ��

	v.resize(id_list.size());

	for (auto i : report) {
		stringstream ss(i);
		string a, b;
		ss >> a >> b;

		int a_idx = find(id_list.begin(), id_list.end(), a) - id_list.begin();
		int b_idx = find(id_list.begin(), id_list.end(), b) - id_list.begin();

		if (find(v[a_idx].begin(), v[a_idx].end(), b) == v[a_idx].end()) {	// ������ ������ �Ű�ó���� 1ȸ�� ����
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