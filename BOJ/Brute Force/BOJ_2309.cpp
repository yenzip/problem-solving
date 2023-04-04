#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> height(9);

	for(int i = 0; i < 9; i++){
		cin >> height[i];
	}

	int sub = accumulate(height.begin(), height.end(), 0) - 100;

	int no_dwarf1, no_dwarf2;
	bool is_find = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (height[i] + height[j] == sub) {
				no_dwarf1 = i;
				no_dwarf2 = j;
				is_find = true;
				break;
			}
		}
		if (is_find) {
			break;
		}
	}

	height.erase(height.begin() + no_dwarf2);
	height.erase(height.begin() + no_dwarf1);

	sort(height.begin(), height.end());

	for (auto h : height) {
		cout << h << '\n';
	}

	return 0;
}