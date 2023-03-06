#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;

	vector<string> v;
	for (int i = 0; i < 26; i++) {
		string tmp;
		tmp.push_back(char('A' + i));
		v.push_back(tmp);
	}

	int i = 0;
	string w = "";
	while (i < msg.size()) {
		w += msg[i];

		int j = i;
		while (find(v.begin(), v.end(), w) != v.end()) {
			w += msg[++j];
		}

		string print = w.substr(0, w.size() - 1);
		int idx = find(v.begin(), v.end(), print) - v.begin();
		answer.push_back(idx + 1);

		if (j < msg.size()) {
			v.push_back(w);
			w.clear();
		}

		i += (j - i);
	}

	return answer;
}