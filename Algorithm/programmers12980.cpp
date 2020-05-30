//점프와 순간 이동
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