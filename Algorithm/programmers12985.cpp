//���� ����ǥ
#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
	int cnt = 0;
	//1. �ڱ� ��ȣ���� �¸��� �� (¦�� ��ȣ / 2)�� �ö�
	//2. ���� �� �� �� a, b ���� => ����

	while (a != b) {
		if (a % 2 == 1) a = (a + 1) / 2;
		else a /= 2;

		if (b % 2 == 1) b = (b + 1) / 2;
		else b /= 2;

		cnt++;
	}
	return cnt;
}