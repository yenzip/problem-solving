#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int a;
	int b;
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		cout << string(a, '*') << endl;
	}
	return 0;
}