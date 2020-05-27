//숫자의 표현
//투포인터
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int numbers[n + 1];

	for (int i = 1; i <= n; i++) {
		numbers[i] = i;
	}

	int start = 1, end = 1, sum = 0;
	while (1) {
		if (sum >= n) {
			sum -= numbers[start];
			start++;
		}
		else {
			if (end == n + 1) break;
			sum += numbers[end];
			end++;
		}
		if (sum == n) answer++;
	}
	return answer;
}