#include <bits/stdc++.h>

using namespace std;

string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string oct;
	cin >> oct;

	for (int i = 0; i < oct.size(); i++) {
		if (oct[i] == '0') {
			if (i == 0) {
				cout << "0";
			}
			else {
				cout << "000";
			}
		}
		else if (oct[i] == '1') {
			if (i == 0) {
				cout << "1";
			}
			else {
				cout << "001";
			}
		}
		else if (oct[i] == '2') {
			if (i == 0) {
				cout << "10";
			}
			else {
				cout << "010";
			}
		}
		else if (oct[i] == '3') {
			if (i == 0) {
				cout << "11";
			}
			else {
				cout << "011";
			}
		}
		else if (oct[i] == '4') {
			cout << "100";
		}
		else if (oct[i] == '5') {
			cout << "101";
		}
		else if (oct[i] == '6') {
			cout << "110";
		}
		else if (oct[i] == '7') {
			cout << "111";
		}
	}
	
	return 0;
}