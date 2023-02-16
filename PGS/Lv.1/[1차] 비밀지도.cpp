#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bitset<16> b;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < arr1.size(); i++) {
		b = (arr1[i] | arr2[i]);
		string tmp = "";
		for (int i = 0; i < n; i++) {
			tmp += b[i] == 1 ? '#' : ' ';
		}
		reverse(tmp.begin(), tmp.end());
		answer.push_back(tmp);
	}

	return answer;
}