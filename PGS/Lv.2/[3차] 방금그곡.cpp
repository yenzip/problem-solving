#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

string replaceHash(string s) {
	s = regex_replace(s, regex("A#"), "a");
	s = regex_replace(s, regex("C#"), "c");
	s = regex_replace(s, regex("D#"), "d");
	s = regex_replace(s, regex("F#"), "f");
	s = regex_replace(s, regex("G#"), "g");
	return s;
}

bool comp(const pair<string, int> &a, const pair<string, int> &b) {
	return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	m = replaceHash(m);

	vector<pair<string, int>> v;	// 곡명, 재생시간
	for (auto musicinfo : musicinfos) {
		stringstream ss(musicinfo);
		string start, end, name, music;
		getline(ss, start, ',');
		getline(ss, end, ',');
		getline(ss, name, ',');
		getline(ss, music, ',');

		int time = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2)) - (stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2)));
		music = replaceHash(music);

		if (time < music.size()) {
			music = music.substr(0, time);
		}
		else {
			int repeat = time / music.size() - 1;
			string tmp = music;
			while (repeat--) {
				music += tmp;
			}
			music += music.substr(0, time % music.size());
		}

		if (music.find(m) != string::npos) {
			v.push_back({ name, time });
		}
	}

	if (v.empty()) {
		answer = "(None)";
	}
	else {
		stable_sort(v.begin(), v.end(), comp);
		answer = v[0].first;
	}

	return answer;
}