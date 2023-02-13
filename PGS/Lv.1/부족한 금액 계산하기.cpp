using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	for (int i = price; i <= price * count; i += price) {
		answer += i;
	}
	return answer < money ? 0 : answer - money;
}
