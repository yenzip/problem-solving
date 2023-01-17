#include <iostream>

using namespace std;

int main() {
	int T;
	int A, B;
	char comma;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> comma >> B;
		cout << A + B << '\n';
	}
	return 0;
}