#include <string>
#include <vector>

using namespace std;

int arr[1000][1000];

vector<int> solution(int n) {
	vector<int> answer;

	int num = 0;
	int m = n * (n + 1) / 2;

	int i = 0, j = 0;
	while (1) {
		if (num >= m) {
			break;
		}

		while (i < n && arr[i][j] == 0) {
			arr[i++][j] = ++num;
		}
		i--;	j++;

		while (j < n && arr[i][j] == 0) {
			arr[i][j++] = ++num;
		}
		i--;	j -= 2;


		while (i > 0 && j > 0 && arr[i][j] == 0) {
			arr[i--][j--] = ++num;
		}
		i += 2; j++;
	}

	int k = 1;
	for (int i = 0; i < n; i++, k++) {
		for (int j = 0; j < k; j++) {
			answer.push_back(arr[i][j]);
		}
	}

	return answer;
}