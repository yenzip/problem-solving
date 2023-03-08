#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	vector<pair<string, string>> res;	// id, state
	map<string, string> m;	// id, name

	for (auto rec : record) {
		stringstream ss(rec);
		string state, id, name;
		if (rec[0] == 'L') {	// Leave ó��
			ss >> state >> id;
		}
		else {
			ss >> state >> id >> name;
			m[id] = name;
		}
		res.push_back({ id, state });
	}

	for (auto v : res) {
		if (v.second == "Enter") {
			answer.push_back(m[v.first] + "���� ���Խ��ϴ�.");
		}
		else if (v.second == "Leave") {
			answer.push_back(m[v.first] + "���� �������ϴ�.");
		}
	}

	return answer;
}