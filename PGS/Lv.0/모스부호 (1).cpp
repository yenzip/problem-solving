#include <bits/stdc++.h>

using namespace std;

string solution(string letter) {
	istringstream ss(letter);
	vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
	vector<string> words;
	string word = "";
	string answer = "";

	while (getline(ss, word, ' ')) {
		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++) {
		int idx = find(morse.begin(), morse.end(), words[i]) - morse.begin();
		answer += alphabet[idx];
	}

	return answer;
}