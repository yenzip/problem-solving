#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int len = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) {
			s[i] = len % 2 ? tolower(s[i]) : toupper(s[i]);
			len++;
		}
		else {
			len = 0;
		}

	}

	return s;
}