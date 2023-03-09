#include <string>
#include <set>
using namespace std;

int isOut(int x, int y) {
	return (x < -5 || x > 5 || y < -5 || y > 5);
}

bool visited[10][10];

int solution(string dirs) {
	int answer = 0;
	int x = 0, y = 0;
	for (auto d : dirs) {
		int nx = x, ny = y;	// next
		if (d == 'U') {
			ny += 1;
		}
		else if (d == 'D') {
			ny -= 1;
		}
		else if (d == 'R') {
			nx += 1;
		}
		else if (d == 'L') {
			nx -= 1;
		}

		if (!isOut(nx, ny) && !visited[nx + 5][ny + 5]) {
			visited[nx + 5][ny + 5] = true;

			x = nx;
			y = ny;
		}
	}

	return s.size();
}