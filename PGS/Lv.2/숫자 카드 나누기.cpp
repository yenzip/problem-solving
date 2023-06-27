#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

bool check(vector<int> array, int gcd) {
	for (int i = 0; i < array.size(); i++) {
		if (array[i] % gcd == 0) {
			return false;
		}
	}
	return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;

	int gcdA = arrayA.size() == 1 ? arrayA[0] : gcd(arrayA[0], arrayA[1]);
	for (int i = 2; i < arrayA.size(); i++) {
		gcdA = gcd(gcdA, arrayA[i]);
	}

	if (check(arrayB, gcdA)) {
		answer = gcdA;
	};

	int gcdB = arrayB.size() == 1 ? arrayB[0] : gcd(arrayB[0], arrayB[1]);
	for (int i = 2; i < arrayB.size(); i++) {
		gcdB = gcd(gcdB, arrayB[i]);
	}

	if (check(arrayA, gcdB)) {
		answer = max(answer, gcdB);
	}

	return answer;
}