#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vowel = { "A", "E", "I", "O", "U" };
vector<string> dictionary;

void dfs(string s) {
	dictionary.push_back(s);

	for (auto v : vowel) {
		if (s.size() < 5) {
			dfs(s + v);
		}
	}
}

int solution(string word) {

	for (auto v : vowel) {
		dfs(v);
	}
	sort(dictionary.begin(), dictionary.end());

	for (int i = 0; i < dictionary.size(); i++) {
		if (dictionary[i] == word) {
			return i + 1;
		}
	}
}