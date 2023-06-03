#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, string>> user;

bool comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		user.push_back({ age, name });
	}

	stable_sort(user.begin(), user.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << user[i].first << " " << user[i].second << "\n";
	}

	return 0;
}