//예상 대진표
#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
	int cnt = 0;
	//1. 자기 번호에서 승리할 때 (짝수 번호 / 2)로 올라감
	//2. 같은 수 될 때 a, b 만남 => 종료

	while (a != b) {
		if (a % 2 == 1) a = (a + 1) / 2;
		else a /= 2;

		if (b % 2 == 1) b = (b + 1) / 2;
		else b /= 2;

		cnt++;
	}
	return cnt;
}