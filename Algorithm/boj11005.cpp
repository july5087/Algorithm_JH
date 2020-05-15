//진법 변환2
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, B;

//10진법 수 N이 주어질 때 B진법으로 바꿔 출력
//10진법 넘어가는 진법 숫자로 표시할 수 없는 경우 알파벳 대문자를 사용
//A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35 (2 ≤ B ≤ 36)
int main() {
	cin >> N >> B;
	vector<char> v;
	string answer;

	while (N >= 0) {
		int r = N % B;

		if (r < 10)
			answer += r + '0'; //int -> char 형변환
		else
			answer += r - 10 + 'A'; //int -> char 형변환
		N /= B;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << "\n";

	return 0;	
}