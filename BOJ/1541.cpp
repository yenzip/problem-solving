#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimiter) {
	vector<string> result;
	stringstream ss(s);
	string tmp;

	while (getline(ss, tmp, delimiter)) {
		result.push_back(tmp);
	}

	return result;
}

int mySum(string s) {
	vector<string> result = split(s, '+');
	int sum = 0;

	for (int i = 0; i < result.size(); i++) {
		sum += stoi(result[i]);
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	
	vector<string> str = split(s, '-');
	int answer = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			answer += mySum(str[i]);
		}
		else {
			answer -= mySum(str[i]);
		}
	}

	cout << answer;

	return 0;
}