//������ ���� �̵�
#include <iostream>
using namespace std;

int solution(int n)
{
	int use = 0;
	while (n > 0) {
		use += n % 2;
		n /= 2;
	}

	return use;
}