//소수 찾기
#include <string>
#include <vector>

using namespace std;

bool isPrime(int num) {

	for (int i = 2; i<num; i++) {
		if (num == 2 || num == 3)
			return true;

		if (num % i == 0)
			return false;
	}
	return true;
}
int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
			answer++;
	}
	return answer;
}