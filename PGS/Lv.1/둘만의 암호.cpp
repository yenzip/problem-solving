#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	char alphabet[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 'a' + i;
	}

	bool is_skip[26] = { false };
	for (auto i : skip) {
		is_skip[i - 'a'] = true;
	}

	for (auto i : s) {
		int idx = index;
		while (1) {
			if (idx == 0) {	// 더 이상 스킵할 것이 없다면 종료
				break;
			}

			int cnt = 0;	// 스킵할 개수
			for (int j = 0; j < idx; j++) {
				if (is_skip[(i - 'a' + j) % 26]) {
					cnt++;
				}
			}

			i = alphabet[(i - 'a' + idx) % 26];
			idx = cnt;
		}
		answer += i;
	}

	return answer;
}