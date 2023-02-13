#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
	if (s.length() != 4 && s.length() != 6) {
		return false;
	}

	for (auto i : s) {
		if (isalpha(i)) {
			return false;
		}
	}
	return true;
}