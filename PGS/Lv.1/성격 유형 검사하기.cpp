#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m = { {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0} };
int s[7] = { 3, 2, 1, 0, 1, 2, 3 };

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";

	for (int i = 0; i < survey.size(); i++) {
		if (choices[i] < 4) {
			m[survey[i][0]] += s[choices[i] - 1];
		}
		else if (choices[i] > 4) {
			m[survey[i][1]] += s[choices[i] - 1];
		}
	}

	answer += m['R'] >= m['T'] ? 'R' : 'T';
	answer += m['C'] >= m['F'] ? 'C' : 'F';
	answer += m['J'] >= m['M'] ? 'J' : 'M';
	answer += m['A'] >= m['N'] ? 'A' : 'N';

	return answer;
}