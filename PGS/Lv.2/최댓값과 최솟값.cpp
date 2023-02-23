#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";

	vector<int> v;

	stringstream ss(s);
	int tmp;
	while (ss >> tmp) {
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	answer += to_string(v.front()) + " " + to_string(v.back());

	return answer;
}