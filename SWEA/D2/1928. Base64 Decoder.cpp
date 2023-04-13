#include <bits/stdc++.h>
using namespace std;

int T;
string S;
map<char, int> m = { {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6 }, { 'H', 7 }, { 'I', 8 }, { 'J', 9 }, { 'K', 10 }, { 'L', 11 }, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15},
					 {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22 }, { 'X', 23 }, { 'Y', 24 }, { 'Z', 25 }, { 'a', 26 }, { 'b', 27 }, {'c', 28}, {'d', 29}, {'e', 30}, {'f', 31},
					 {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38 }, { 'n', 39 }, { 'o', 40 }, { 'p', 41 }, { 'q', 42 }, { 'r', 43 }, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47},
					 {'w', 48}, {'x', 49}, {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54 }, { '3', 55 }, { '4', 56 }, { '5', 57 }, { '6', 58 }, { '7', 59 }, {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S;
		string bin;
		for (int i = 0; i < S.size(); i++) {
			bitset<6> bit(m[S[i]]);
			bin += bit.to_string();
		}

		string answer;
		for (int i = 0; i < bin.size(); i += 8) {
			bitset<8>bit(bin.substr(i, 8));
			int n = bit.to_ulong();
			answer += char(n);
		}
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}