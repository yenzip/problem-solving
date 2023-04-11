#include <bits/stdc++.h>
using namespace std;

int T;
map<int, int> m = {
	{1, 31}, {2, 28},
	{3, 31}, {4, 30},
	{5, 31}, {6, 30},
	{7, 31}, {8, 31},
	{9, 30}, {10, 31},
	{11, 30}, {12, 31}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		string date;
		cin >> date;
		string year = date.substr(0, 4);
		string month = date.substr(4, 2);
		string day = date.substr(6, 2);
		cout << "#" << i << " ";
		if (stoi(day) <= m[stoi(month)]) {
			cout << year << '/' << month << '/' << day << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}