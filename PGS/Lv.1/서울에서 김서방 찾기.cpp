#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
	answer = "�輭���� " + to_string(pos) + "�� �ִ�";
	return answer;
}