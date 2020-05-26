//다음 큰 숫자
#include <vector>
using namespace std;

bool rule_two(int a, int b) {
	vector<int> v_a, v_b; //a, b 2진수
	int cnt_a = 0, cnt_b = 0; //a, b 2진수의 1 갯수

	//2진수 변환
	while (a > 0) {
		//1 갯수 카운트
		if (a % 2 == 1) cnt_a++;
		v_a.push_back(a % 2);
		a /= 2;
	}
	while (b > 0) {
		//1 갯수 카운트
		if (b % 2 == 1) cnt_b++;
		v_b.push_back(b % 2);
		b /= 2;
	}
	//2진수 순서 원래 뒤집어야 맞지만 갯수만 확인하므로 pass
	//1 갯수 같은지 확인
	if (cnt_a == cnt_b) return true;
	else return false;
}

int solution(int n) {
	int answer = 0;

	for (int i = n + 1; i <= 1000000; i++) {
		//2진수 변환 후 1 갯수 같은지 확인
		if (rule_two(n, i)) {
			answer = i;
			break;
		}
	}
	return answer;
}