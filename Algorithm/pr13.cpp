#include <iostream>
#include <ctime> 
using namespace std;

int main() {
	clock_t start, end;
	double result;
	start = clock(); //시간측정 시작

	long long N, answer = 1;
	cin >> N;
	int remain = N;

	if (N <= 2) answer = 1;
	if (N == 3) answer = 2;
	if (N == 4) answer = 4;

	if (N >= 5) {
		while (remain >= 3 && remain != 4) {
			answer *= 3;
			remain -= 3;
		}
		if (remain != 0) answer *= remain;
	}

	cout << answer << "\n";

	end = clock(); //시간 측정 끝
	result = (double)(end - start);
	cout << "result : " << ((result) / CLOCKS_PER_SEC) << "seconds" << "\n";

	return 0;
}