#include <bits/stdc++.h>
using namespace std;

int N, x, y;
struct Point {
	int x;
	int y;
};
vector<Point> v;

bool comp(Point a, Point b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}