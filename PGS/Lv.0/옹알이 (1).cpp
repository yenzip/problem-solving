#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	for (auto b : babbling) {
		int len = 0;

		if (b.find("aya") != string::npos) {
			len += 3;
		}
		if (b.find("ye") != string::npos) {
			len += 2;
		}
		if (b.find("woo") != string::npos) {
			len += 3;
		}
		if (b.find("ma") != string::npos) {
			len += 2;
		}

		if (b.size() == len) {
			answer++;
		}
	}

	return answer;
}