#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int solution(string s) {
	int answer = 0;

	stringstream ss(s);
	vector<int> v;

	string tmp;
	while (ss >> tmp) {
		if (tmp == "Z") {
			v.pop_back();
		}
		else {
			v.push_back(stoi(tmp));
		}
	}

	answer = accumulate(v.begin(), v.end(), 0);

	return answer;
}