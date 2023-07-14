#include <bits/stdc++.h>
using namespace std;

struct Info {
	string name;
	int kor;
	int eng;
	int math;
};

int N;
string name;
int kor, eng, math;
vector<Info> A;

bool compare(Info a, Info b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> kor >> eng >> math;
		A.push_back({ name, kor, eng, math });
	}

	sort(A.begin(), A.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << A[i].name << "\n";
	}

	return 0;
}