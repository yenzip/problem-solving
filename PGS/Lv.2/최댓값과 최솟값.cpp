#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
	stringstream ss(s);
	int x, minVal = INT_MAX, maxVal = INT_MIN;

	while (ss >> x) {
		minVal = min(minVal, x);
		maxVal = max(maxVal, x);
	}

	string answer = to_string(minVal) + " " + to_string(maxVal);

	return answer;
}