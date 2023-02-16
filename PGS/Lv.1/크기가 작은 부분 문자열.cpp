#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
	int answer = 0;

	int n = p.size();
	for (int i = 0; i < t.size() - n + 1; i++) {
		string s = t.substr(i, n);

		if (s <= p) {
			answer++;
		}
	}

	return answer;
}