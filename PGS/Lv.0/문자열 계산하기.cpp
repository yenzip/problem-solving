#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
	int answer = 0;
	istringstream ss(my_string);
	vector<string> v;
	string tmp = "";

	while (getline(ss, tmp, ' ')) {
		v.push_back(tmp);
	}

	answer = stoi(v[0]);
	for (int i = 1; i < v.size(); i += 2) {
		if (v[i] == "+") {
			answer = answer + stoi(v[i + 1]);
		}
		else {
			answer = answer - stoi(v[i + 1]);
		}
	}

	return answer;
}