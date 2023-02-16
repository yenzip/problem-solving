#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, char> m = { {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five",'5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'} }; 

int solution(string s) {
	int answer = 0;

	string num = "";
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			num += s[i];
		}
		else {
			tmp += s[i];
			if (m.find(tmp) != m.end()) {
				num += m[tmp];
				tmp = "";
			}
		}
	}

	answer = stoi(num);

	return answer;
}