#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	for (auto b : babbling) {
		int idx = 0;
		string tmp = "";
		while (idx < b.size()) {
			if (tmp != "aya" && b.substr(idx, 3) == "aya") {
				idx += 3;
				tmp = "aya";
			}
			else if (tmp != "ye" && b.substr(idx, 2) == "ye") {
				idx += 2;
				tmp = "ye";
			}
			else if (tmp != "woo" && b.substr(idx, 3) == "woo") {
				idx += 3;
				tmp = "woo";
			}
			else if (tmp != "ma" && b.substr(idx, 2) == "ma") {
				idx += 2;
				tmp = "ma";
			}
			else {
				break;
			}
		}
		if (idx == b.size()) {
			answer++;
		}
	}

	return answer;
}