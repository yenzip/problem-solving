#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	// 1.
	stringstream ss(today);
	vector<int> t(3);	// today(년, 월, 일)
	char c = '.';
	ss >> t[0] >> c >> t[1] >> c >> t[2] >> c;
	int today_N = t[0] * 28 * 12 + t[1] * 28 + t[2];

	// 2.
	map<char, int> mp;	// terms(종류, 일수)
	for (auto i : terms) {
		stringstream ss(i);
		char t;
		int month, day;
		ss >> t >> month;
		day = month * 28;
		mp.insert({ t, day });
	}

	// 3.
	int idx = 1;
	for (auto i : privacies) {
		stringstream ss1(i);
		string date;
		char t;
		ss1 >> date >> t;

		stringstream ss2(date);
		int y, m, d;
		ss2 >> y >> c >> m >> c >> d;
		int start_N = y * 28 * 12 + m * 28 + d;

		if (start_N + mp[t] <= today_N) {
			answer.push_back(idx);
		}

		idx++;
	}

	return answer;
}